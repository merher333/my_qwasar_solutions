#include "my_ls.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

struct fileinfo {
    char *name;
    struct timespec mtime;
};

//Bubble sort algorithm for sorting file names
void bubble_sort(struct fileinfo arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
                struct fileinfo temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Bubble sort algorithm for sorting directory names
void sort_paths_with_bubble(char *paths[], int path_count) {
    struct fileinfo temp[256];

    // Copy paths into temporary fileinfo structs
    for (int i = 0; i < path_count; i++) {
        temp[i].name = paths[i];
    }

    // Use bubble_sort
    bubble_sort(temp, path_count);

    // Copy sorted names back into paths[]
    for (int i = 0; i < path_count; i++) {
        paths[i] = temp[i].name;
    }
}

// Function that sorts modification time (descending)
void sort_by_mtime(struct fileinfo arr[], int n) {
    int swapped;
    do {
        swapped = 0;
        for (int i = 0; i < n - 1; i++) {
            // Compare timespec properly
            if (arr[i].mtime.tv_sec < arr[i + 1].mtime.tv_sec || 
               (arr[i].mtime.tv_sec == arr[i + 1].mtime.tv_sec &&
                arr[i].mtime.tv_nsec < arr[i + 1].mtime.tv_nsec)) {

                struct fileinfo tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swapped = 1;
            }
        }
    } while (swapped);
}

// Print the content of directories
int list_directories(char *paths[], int path_count, int flag_a, int flag_t, int flag_1) {
    DIR *dir;
    struct dirent *entry;
    struct fileinfo files[1024];
    int count = 0;

    // Sort the directory names
    sort_paths_with_bubble(paths, path_count);

    for(int i = 0; i < path_count; i++) {
        // Only print a newline before directories after the first one
        if (path_count > 1 && i > 0) {
            printf("\n");
        }
        
        if(path_count > 1) {
            printf("%s:\n", paths[i]);
        }
        
        count = 0; // reset list for each directory
        dir = opendir(paths[i]);
        if (dir == NULL) {
            perror(paths[i]);
            continue;
        }

    // Read directory entries (skip hidden)
    while ((entry = readdir(dir)) != NULL && count < 1024) {
        if (entry->d_name[0] == '.' && !flag_a)
            continue;

        // Allocate and copy filename
        files[count].name = strdup(entry->d_name);

        // Build full path: <directory>/<entry>
        char fullpath[PATH_MAX];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", paths[i], entry->d_name);

        // Now stat the full path
        struct stat st;
        if (stat(fullpath, &st) == -1) {
            perror(fullpath);
            free(files[count].name);
            continue;
        }

        files[count].mtime = st.st_mtim;
        count++;
    }

    closedir(dir);

    // Sort alphabetically (by default)
    bubble_sort(files, count);
    
    // Sort by time
    if(flag_t) sort_by_mtime(files, count);

    // Print like ls
    for (int i = 0; i < count; i++) {
        printf("%s\n", files[i].name);
        free(files[i].name);
    }

    // Print in one column
    if(flag_1) {}

    }
    return 0;
}

// Argument parsing
int my_ls(int argc, char *argv[]) {
    int flag_a = 0;
    int flag_t = 0;
    int flag_1 = 0;

    char *paths[256];
    int path_count = 0;

    // Start from i=1 because argv[0] is program name
    for(int i = 1; i < argc; i++) {
        if(argv[i][0] == '-') {
            // It's a flag argument
            for(int j = 1; argv[i][j]; j++) {
                if(argv[i][j] == 'a') flag_a = 1;
                if(argv[i][j] == 't') flag_t = 1;
                if(argv[i][j] == '1') flag_1 = 1;
            }
        } else {
            // It's a directory name
            paths[path_count++] = argv[i];
        }
    }
    // If user gave no directories, use "."
    if(path_count == 0) {
        paths[path_count++] = ".";
    }
    list_directories(paths, path_count, flag_a, flag_t, flag_1);

    return 0;
}

// Main
int main(int argc, char *argv[]) {  
    return my_ls(argc, argv);
}
