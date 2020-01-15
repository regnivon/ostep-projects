//
// Created by Quentin Novinger on 1/15/20.
//
#include <stdio.h>
#include <stdlib.h>
#define BUFF 180

int main(int argc, char *argv[]) {

    for (int i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "r");
        if (f == NULL) {
            printf("wcat: cannot open file\n");
            exit(1);
        }

        char line[BUFF];
        char *suc = fgets(line, BUFF, f);

        while (suc != NULL) {
            printf("%s", line);
            suc = fgets(line, BUFF, f);
        }
    }

    return 0;

}