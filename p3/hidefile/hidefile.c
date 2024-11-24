#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <dlfcn.h>	/* for dynamic loading */

// Name: Yuet Yue 
// netID: yy655
// your code for readdir goes here

typedef struct dirent *(*orig_readdir_t)(DIR *);
orig_readdir_t orig_readdir;

static char **hidden_list = NULL; // List of HIDDEN files
static int hidden_count = 0; // Number of HIDDEN files

// This function adds the HIDDEN environment variable into a static list
void parse_hidden_env() {
    const char *hidden_env = getenv("HIDDEN");
    if (!hidden_env || strlen(hidden_env) == 0) {
        hidden_list = NULL;
        hidden_count = 0;
        return;
    }

    char *hidden_files = strdup(hidden_env);
    char *token = strtok(hidden_files, ":");
    while (token) {
        hidden_list = realloc(hidden_list, (hidden_count + 1) * sizeof(char *));
        hidden_list[hidden_count++] = strdup(token);
        token = strtok(NULL, ":");
    }
    free(hidden_files);
}

// This function checks if a file is hidden
int is_hidden(const char *filename) {
    if (!hidden_list) return 0;  
    for (int i = 0; i < hidden_count; i++) {
        if (strcmp(hidden_list[i], filename) == 0) {
            return 1;
        }
    }
    return 0;
}

struct dirent *readdir(DIR *dirp) {
    if (!orig_readdir) {
        orig_readdir = (orig_readdir_t)dlsym(RTLD_NEXT, "readdir");
        if (!orig_readdir) {
            fprintf(stderr, "Failed to load the original readdir: %s\n", dlerror());
            exit(EXIT_FAILURE);
        }
    }

    // Add the HIDDEN on the first call
    static int initialized = 0;
    if (!initialized) {
        parse_hidden_env();
        initialized = 1;
    }

    struct dirent *entry;
    while ((entry = orig_readdir(dirp)) != NULL) {
        if (!is_hidden(entry->d_name)) {
            return entry;
        }
    }
    return NULL; 
}