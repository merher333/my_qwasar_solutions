#include "my_ls.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/* Hold a filename + its stat info */
typedef struct {
    char *name;
    struct stat st;
} Entry;

/* Lexicographical compare by name */
int compare_name(const void *a, const void *b)
{
    const Entry *ea = a, *eb = b;
    return strcmp(ea->name, eb->name);
}

/* Compare by modification time (newest first), tie-break on nanosec */
int compare_time(const void *a, const void *b)
{
    const Entry *ea = a, *eb = b;
    if (ea->st.st_mtim.tv_sec != eb->st.st_mtim.tv_sec)
        return (eb->st.st_mtim.tv_sec - ea->st.st_mtim.tv_sec);
    return (eb->st.st_mtim.tv_nsec - ea->st.st_mtim.tv_nsec);
}

/* Bubble-sort an Entry array */
static void sort_entries(Entry *arr, int n,
                         int (*cmp)(const void *, const void *))
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (cmp(&arr[j], &arr[j+1]) > 0) {
                Entry tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
}

/* Bubble-sort a string array */
static void sort_names(char **arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (strcmp(arr[j], arr[j+1]) > 0) {
                char *t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
}

/* Parse -a and -t flags, return first non-option index */
void parse_options(int argc, char **argv,
                   int *show_all, int *sort_time,
                   int *first_operand)
{
    int i = 1;
    *show_all  = 0;
    *sort_time = 0;

    while (i < argc && argv[i][0] == '-' && argv[i][1] != '\0')
    {
        char *opt = argv[i];
        int j;
        // parse each letter after the dash
        for (j = 1; opt[j] != '\0'; j++)
        {
            if      (opt[j] == 'a') *show_all  = 1;
            else if (opt[j] == 't') *sort_time = 1;
            else
                // unknown flag: stop processing options altogether
                goto done_opts;
        }
        i++;
    }
done_opts:
    *first_operand = i;
}
/* List a single file operand */
static void list_files(char **names, int count, int sort_time)
{
    Entry *e = malloc(sizeof(Entry) * count);
    int n = 0;
    for (int i = 0; i < count; i++) {
        if (lstat(names[i], &e[n].st) == 0) {
            e[n].name = names[i];
            n++;
        }
    }
    if (sort_time) sort_entries(e, n, compare_time);
    else           sort_entries(e, n, compare_name);
    for (int i = 0; i < n; i++)
        printf("%s\n", e[i].name);
    free(e);
}

/*
** Read a directory’s contents into an Entry[],
** filter dot-files if !show_all, stat via full path,
** sort and print just the basenames.
*/
static void list_dir_path(const char *path, int show_all, int sort_time)
{
    DIR *d = opendir(path);
    if (!d) return;

    struct dirent *de;
    Entry *arr = NULL;
    int n = 0;

    while ((de = readdir(d))) {
        char *name = de->d_name;
        if (!show_all && name[0] == '.') continue;

        Entry *tmp = realloc(arr, sizeof(Entry)*(n+1));
        if (!tmp) break;
        arr = tmp;

        /* save basename */
        arr[n].name = strdup(name);
        if (!arr[n].name) break;

        /* build full path for stat */
        size_t L = strlen(path) + 1 + strlen(name) + 1;
        char *full = malloc(L);
        if (!full) {
            free(arr[n].name);
            break;
        }
        snprintf(full, L, "%s/%s", path, name);

        if (lstat(full, &arr[n].st) == -1) {
            free(arr[n].name);
            free(full);
            continue;
        }
        free(full);
        n++;
    }
    closedir(d);

    if (sort_time) sort_entries(arr, n, compare_time);
    else           sort_entries(arr, n, compare_name);

    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i].name);
        free(arr[i].name);
    }
    free(arr);
}

int main(int argc, char **argv)
{
    int show_all, sort_time, first;
    parse_options(argc, argv, &show_all, &sort_time, &first);

    int total = argc - first;
    /* No operands: list current dir */
    if (total == 0) {
        list_dir_path(".", show_all, sort_time);
    }
    /* Exactly one operand: no header */
    else if (total == 1) {
        struct stat st;
        char *nm = argv[first];
        if (lstat(nm, &st) == 0 && S_ISDIR(st.st_mode)) {
            list_dir_path(nm, show_all, sort_time);
        } else {
            list_files(&nm, 1, sort_time);
        }
    }
    /* Multiple operands: files first, then dirs with headers */
    else {
        char **files = malloc(sizeof(char*)*total);
        char **dirs  = malloc(sizeof(char*)*total);
        int nf = 0, nd = 0;

        for (int i = first; i < argc; i++) {
            struct stat st;
            if (lstat(argv[i], &st)==0 && S_ISDIR(st.st_mode))
                dirs[nd++] = argv[i];
            else
                files[nf++] = argv[i];
        }

        if (nf) {
            list_files(files, nf, sort_time);
        }

        if (nd) {
            if (nf) printf("\n");
            sort_names(dirs, nd);
            for (int i = 0; i < nd; i++) {
                printf("%s:\n", dirs[i]);
                list_dir_path(dirs[i], show_all, sort_time);
                if (i < nd-1) printf("\n");
            }
        }

        free(files);
        free(dirs);
    }

    return 0;
}
