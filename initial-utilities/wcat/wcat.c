//
// Created by Quentin Novinger on 1/15/20.
//
#include <stdio.h>

int main(int argc, char *argv[]) {

    for (int i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], 'r');
        if (f == NULL) {
            printf("cannot open file\n");
            exit(1);
        }
        char *line = NULL;
        fgets(f)
        while (line != NULL) {
            printf("%s", line);
            line = fgets(f);
        }
    }

    return 0;

}