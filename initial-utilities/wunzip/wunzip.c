//
// Created by Quentin Novinger on 1/15/20.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        puts("wunzip: file1 [file2 ...]");
        exit(1);
    }
    for(int i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "r");
        if (f == NULL) {
            printf("wunzip: cannot open file\n");
            exit(1);
        }
        fseek(f, 0, SEEK_END);
        long fSize = ftell(f);
        rewind(f);
        int *buff = malloc(1 * sizeof(int));
        char* b2 = malloc(1 * sizeof(char));
        while (fread(buff, 4, 1, f) > 0) {
            if (fread(b2, 1, 1, f) > 0) {
                for (int i = 0; i < *buff; i++) {
                    printf("%c", *b2);
                }
            }
        }
        free(b2);
        fclose(f);
        free(buff);
    }
}
