//
// Created by Quentin Novinger on 1/15/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        puts("wgrep: searchterm [file ...]");
        exit(1);
    }
    // get the search term
    char *match = argv[1];
    // if empty string matches nothing
    if (strcmp("""", match) == 0){
        exit(0);
    }
    // if no file args read from stdin, else read from files
    if(argc == 2){
        char *line = malloc(10 * sizeof(char));
        size_t cap = 10;
        ssize_t linelen;
        while ((linelen = getline(&line, &cap, stdin)) > 0) {
            if(strstr(line, match) != NULL) {
                printf("%s", line);
            }
        }
    // else a file(s) passed, grep them all line by line
    } else {
        for (int i = 2; i < argc; i++) {
            FILE *f = fopen(argv[i], "r");
            if (f == NULL) {
                printf("wgrep: cannot open file\n");
                exit(1);
            }
            char *line = malloc(10 * sizeof(char));
            size_t cap = 10;
            ssize_t linelen;
            while ((linelen = getline(&line, &cap, f)) > 0) {
                if(strstr(line, match) != NULL) {
                    printf("%s", line);
                }
            }
            free(line);
            fclose(f);
        }
    }
    return 0;
}


