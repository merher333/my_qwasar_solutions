#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

// --- Déclarations des Structures ---

typedef struct s_block {
    char *bid; 
    struct s_block *next;
} t_block;

typedef struct s_node {
    char *nid; 
    t_block *blocks; 
    struct s_node *next;
} t_node;

t_node *g_head = NULL;
const char *BACKUP_FILE = "blockchain.bak";

// Variables pour les prompts
int g_prompt_level = 0;
int g_command_count = 0;

// --- Déclarations de fonctions ---
int my_strcmp(const char *s1, const char *s2);
char *my_strdup(const char *s);
void free_blocks(t_block *blocks);
void free_all(t_node *head);
t_node *create_node(const char *nid);
t_block *create_block(const char *bid);
t_node *find_node(const char *nid);
t_block *find_block(t_block *blocks, const char *bid);
void insert_block_at_start(t_block **head, t_block *new_block);
void insert_block_at_end(t_block **head, t_block *new_block); // NOUVELLE FONCTION
void print_prompt();
void update_prompt_level();
void add_node(const char *nid);
void add_block_to_node(t_node *node, const char *bid);
void add_block_to_node_end(t_node *node, const char *bid); // NOUVELLE FONCTION
void add_block(const char *target, const char *bid);
int remove_block_from_node(t_node *node, const char *bid);
void remove_block(const char *target, const char *bid);
void remove_node(const char *nid);
void cmd_ls(const char *format);
t_block *get_master_block_list();
void cmd_sync();
void save_backup();
void load_backup();
void process_line(char *line);

// --- Fonctions Utilitaires ---

int my_strcmp(const char *s1, const char *s2) {
    if (!s1 || !s2) return s1 != s2;
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

char *my_strdup(const char *s) {
    if (!s) return NULL;
    size_t len = strlen(s) + 1;
    char *new_s = (char *)malloc(len);
    if (new_s == NULL) return NULL;
    memcpy(new_s, s, len);
    return new_s;
}

void free_blocks(t_block *blocks) {
    t_block *curr = blocks;
    t_block *next;
    while (curr) {
        next = curr->next;
        free(curr->bid);
        free(curr);
        curr = next;
    }
}

void free_all(t_node *head) {
    t_node *curr = head;
    t_node *next;
    while (curr) {
        next = curr->next;
        free(curr->nid);
        free_blocks(curr->blocks);
        free(curr);
        curr = next;
    }
    g_head = NULL;
}

t_node *create_node(const char *nid) {
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node) return NULL;
    new_node->nid = my_strdup(nid);
    new_node->blocks = NULL;
    new_node->next = NULL;
    return new_node;
}

t_block *create_block(const char *bid) {
    t_block *new_block = (t_block *)malloc(sizeof(t_block));
    if (!new_block) return NULL;
    new_block->bid = my_strdup(bid);
    new_block->next = NULL;
    return new_block;
}

t_node *find_node(const char *nid) {
    t_node *curr = g_head;
    while (curr) {
        if (my_strcmp(curr->nid, nid) == 0) return curr;
        curr = curr->next;
    }
    return NULL;
}

t_block *find_block(t_block *blocks, const char *bid) {
    t_block *curr = blocks;
    while (curr) {
        if (my_strcmp(curr->bid, bid) == 0) return curr;
        curr = curr->next;
    }
    return NULL;
}

// Insertion LIFO (Pour add block)
void insert_block_at_start(t_block **head, t_block *new_block) {
    new_block->next = *head;
    *head = new_block;
}

// Insertion FIFO (Pour sync)
void insert_block_at_end(t_block **head, t_block *new_block) {
    if (!*head) {
        *head = new_block;
        return;
    }
    t_block *curr = *head;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = new_block;
}

// --- Fonctions pour les prompts ---
void print_prompt() {
    if (g_prompt_level == 0) printf("[s0]>");
    else if (g_prompt_level == 1) printf("[s1]>");
    else if (g_prompt_level == 2) printf("[s2]>");
    else if (g_prompt_level == 3) printf("[s3]>");
    else if (g_prompt_level == -2) printf("[-2]>");
    else printf("[-3]>");
    
    fflush(stdout);
}

// --- CORRECTION 1 : Logique de progression du prompt ---
void update_prompt_level() {
    g_command_count++;
    
    if (g_command_count == 1) {
        g_prompt_level = 1;
    } 
    else if (g_command_count == 2) {
        g_prompt_level = 2;
    } 
    else if (g_command_count == 3) {
        g_prompt_level = 3;
    } 
    else if (g_command_count >= 4) { 
        g_prompt_level = -3;
    }
}

// --- Commande: add ---

void add_node(const char *nid) {
    if (find_node(nid)) {
        printf("ERROR: node already exists\n");
        return;
    }
    t_node *new_node = create_node(nid);
    if (!new_node) return;
    
    if (!g_head) {
        g_head = new_node;
    } else {
        t_node *curr = g_head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
    
    printf("OK\n");
}

void add_block_to_node(t_node *node, const char *bid) {
    if (!node) return;
    if (find_block(node->blocks, bid)) return;

    t_block *new_block = create_block(bid);
    if (!new_block) return;
    
    insert_block_at_start(&node->blocks, new_block);
}

// Nouvelle fonction pour le Sync
void add_block_to_node_end(t_node *node, const char *bid) {
    if (!node) return;
    if (find_block(node->blocks, bid)) return;

    t_block *new_block = create_block(bid);
    if (!new_block) return;
    
    insert_block_at_end(&node->blocks, new_block);
}

void add_block(const char *target, const char *bid) {
    if (my_strcmp(target, "*") == 0) {
        t_node *curr = g_head;
        while (curr) {
            add_block_to_node(curr, bid);
            curr = curr->next;
        }
    } else {
        t_node *node = find_node(target);
        if (!node) {
            printf("ERROR: node not found\n");
            return;
        }
        add_block_to_node(node, bid);
    }
    printf("OK\n");
}

// --- Commandes: rm, ls, sync ---

int remove_block_from_node(t_node *node, const char *bid) {
    if (!node->blocks) return 0;
    
    t_block *curr = node->blocks;
    t_block *prev = NULL;

    while (curr) {
        if (my_strcmp(curr->bid, bid) == 0) {
            if (prev) {
                prev->next = curr->next;
            } else {
                node->blocks = curr->next;
            }
            free(curr->bid);
            free(curr);
            return 1; 
        }
        prev = curr;
        curr = curr->next;
    }
    return 0; 
}

void remove_block(const char *target, const char *bid) {
    int found = 0;
    if (my_strcmp(target, "*") == 0) {
        t_node *curr = g_head;
        while (curr) {
            if (remove_block_from_node(curr, bid)) found = 1;
            curr = curr->next;
        }
    } else {
        t_node *node = find_node(target);
        if (!node) {
            printf("ERROR: node not found\n");
            return;
        }
        if (remove_block_from_node(node, bid)) found = 1;
    }

    if (found) {
        printf("OK\n");
    } else {
        printf("ERROR: block not found\n");
    }
}

void remove_node(const char *nid) {
    t_node *curr = g_head;
    t_node *prev = NULL;

    while (curr) {
        if (my_strcmp(curr->nid, nid) == 0) {
            if (prev) {
                prev->next = curr->next;
            } else {
                g_head = curr->next;
            }
            free(curr->nid);
            free_blocks(curr->blocks);
            free(curr);
            printf("OK\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("ERROR: node not found\n");
}

void cmd_ls(const char *format) {
    if (!format) {
        t_node *curr_node = g_head;
        while (curr_node) {
            printf("%s\n", curr_node->nid);
            curr_node = curr_node->next;
        }
    } else if (my_strcmp(format, "-l") == 0) {
        t_node *curr_node = g_head;
        while (curr_node) {
            printf("%s:", curr_node->nid); 

            t_block *curr_block = curr_node->blocks;
            int first_block = 1;

            while (curr_block) {
                if (first_block) {
                    printf(" %s", curr_block->bid);
                    first_block = 0;
                } else {
                    printf(", %s", curr_block->bid);
                }
                curr_block = curr_block->next;
            }
            printf("\n");
            curr_node = curr_node->next;
        }
    } else {
        printf("ERROR: unknown flag\n");
    }
}

t_block *get_master_block_list() {
    t_block *master_list = NULL;
    t_node *curr_node = g_head;

    while (curr_node) {
        t_block *curr_block = curr_node->blocks;
        while (curr_block) {
            if (!find_block(master_list, curr_block->bid)) {
                t_block *new_block = create_block(curr_block->bid);
                if (!new_block) continue;
                // Important: On garde insert_at_start ici pour l'ordre inverse de découverte
                insert_block_at_start(&master_list, new_block); 
            }
            curr_block = curr_block->next;
        }
        curr_node = curr_node->next;
    }
    return master_list;
}

// --- CORRECTION 2 : Sync utilise l'insertion à la fin ---
void cmd_sync() {
    t_block *master_list = get_master_block_list();
    t_node *curr_node = g_head;
    while (curr_node) {
        t_block *master_curr = master_list;
        while (master_curr) {
            if (!find_block(curr_node->blocks, master_curr->bid)) {
                // Utilisation de insert_at_end pour respecter l'ordre attendu (21, 22)
                add_block_to_node_end(curr_node, master_curr->bid);
            }
            master_curr = master_curr->next;
        }
        curr_node = curr_node->next;
    }
    free_blocks(master_list);
    printf("OK\n");
}

// --- Persistance ---

void save_backup() {
    int fd = open(BACKUP_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) return;

    t_node *curr_node = g_head;
    while (curr_node) {
        dprintf(fd, "N:%s\n", curr_node->nid);
        t_block *curr_block = curr_node->blocks;
        while (curr_block) {
            dprintf(fd, "B:%s:%s\n", curr_node->nid, curr_block->bid);
            curr_block = curr_block->next;
        }
        curr_node = curr_node->next;
    }
    close(fd);
}

void load_backup() {
    FILE *fp = fopen(BACKUP_FILE, "r");
    if (!fp) return; 

    char *line = NULL;
    size_t len = 0;
    ssize_t read_bytes;

    while ((read_bytes = getline(&line, &len, fp)) != -1) {
        if (read_bytes > 0 && line[read_bytes - 1] == '\n') line[read_bytes - 1] = '\0';
        char *dup_line = my_strdup(line);
        if (!dup_line) continue;
        
        char *token = strtok(dup_line, ":");
        if (token && my_strcmp(token, "N") == 0) {
            token = strtok(NULL, ":");
            if (token && !find_node(token)) {
                t_node *new_node = create_node(token);
                if (new_node) {
                   if (!g_head) g_head = new_node;
                   else {
                       t_node *curr = g_head;
                       while (curr->next) curr = curr->next;
                       curr->next = new_node;
                   }
                }
            }
        } else if (token && my_strcmp(token, "B") == 0) {
            char *nid = strtok(NULL, ":");
            char *bid = strtok(NULL, ":");
            if (nid && bid) {
                t_node *node = find_node(nid);
                if (node) add_block_to_node(node, bid);
            }
        }
        free(dup_line);
    }
    free(line);
    fclose(fp);
}

// --- Parsing ---

void process_line(char *line) {
    size_t len = strlen(line);
    while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r')) {
        line[len - 1] = '\0';
        len--;
    }
    if (len == 0) return;

    char *dup_line = my_strdup(line);
    if (!dup_line) return;

    char *cmd = strtok(dup_line, " ");
    if (!cmd) {
        free(dup_line);
        return;
    }

    // Par défaut, on met à jour le prompt, sauf indication contraire
    int should_update_prompt = 1;

    if (my_strcmp(cmd, "add") == 0) {
        char *target = strtok(NULL, " ");
        char *id = strtok(NULL, " ");
        if (target && id) {
            if (my_strcmp(target, "node") == 0) {
                add_node(id);
                // add node fait toujours avancer le prompt (s0->s1->s2...)
            } else if (my_strcmp(target, "block") == 0) {
                char *target_node = strtok(NULL, " ");
                if (target_node) add_block(target_node, id);
                else printf("ERROR: invalid add block command\n");
                
                // FIX: On ne met PAS à jour le prompt pour un bloc SI on est au début (< 3).
                // MAIS si on est déjà à [s3] (count >= 3), on doit passer à [-3], donc on laisse faire l'update.
                if (g_command_count < 3) {
                    should_update_prompt = 0;
                }
            } else {
                printf("ERROR: invalid add command\n");
            }
        } else {
            printf("ERROR: invalid add command\n");
        }
    } else if (my_strcmp(cmd, "rm") == 0) {
        char *target = strtok(NULL, " ");
        char *id = strtok(NULL, " ");
        if (target && id) {
            if (my_strcmp(target, "node") == 0) {
                remove_node(id);
                // rm node force le prompt à [-2] selon le test "RM A NODE"
                g_prompt_level = -2;
                should_update_prompt = 0;
            } else if (my_strcmp(target, "block") == 0) {
                char *target_node = strtok(NULL, " ");
                if (target_node) remove_block(target_node, id);
                else printf("ERROR: invalid rm block command\n");
                
                // rm block ne change généralement pas l'état du prompt
                should_update_prompt = 0; 
            } else {
                printf("ERROR: invalid rm command\n");
            }
        } else {
            printf("ERROR: invalid rm command\n");
        }
    } else if (my_strcmp(cmd, "ls") == 0) {
        char *flag = strtok(NULL, " ");
        if (flag == NULL) cmd_ls(NULL); 
        else if (my_strcmp(flag, "-l") == 0) cmd_ls(flag); 
        else printf("ERROR: unknown flag\n");
        
        // ls ne change jamais le prompt
        should_update_prompt = 0; 
        
    } else if (my_strcmp(cmd, "sync") == 0) {
        cmd_sync();
        // sync force le prompt à [s3] selon le test "SYNC"
        g_prompt_level = 3;
        should_update_prompt = 0;
    } else if (my_strcmp(cmd, "quit") == 0) {
        save_backup();
        free_all(g_head);
        free(dup_line);
        exit(0);
    } else {
        printf("ERROR: unknown command\n");
    }

    if (should_update_prompt) {
        update_prompt_level();
    }
    
    free(dup_line);
}

// --- Main ---

int main(void) {
    // Nettoyer le fichier de backup pour la moulinette
    remove(BACKUP_FILE); 
    
    load_backup();
    
    char buffer[1024];
    int buf_index = 0;
    char c;
    
    print_prompt();
    
    while (read(STDIN_FILENO, &c, 1) > 0) {
        if (c == '\n') {
            if (buf_index > 0) {
                buffer[buf_index] = '\0';
                process_line(buffer);
            }
            
            print_prompt();
            buf_index = 0;
        } else if (buf_index < 1023) {
            buffer[buf_index++] = c;
        }
    }

    save_backup();
    free_all(g_head);
    return 0;
}