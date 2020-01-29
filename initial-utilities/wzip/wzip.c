//
// Created by Quentin Novinger on 1/15/20.
//

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    if (argc < 2) {
        puts("wzip: file1 [file2 ...]");
        exit(1);
    }
    char cur;
    int curCharCount = 1;
    for(int i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "r");
        if (f == NULL) {
            printf("wzip: cannot open file\n");
            exit(1);
        }
        fseek (f, 0, SEEK_END);
        long fSize = ftell(f);
        rewind(f);
        char *buff = malloc(fSize * sizeof(char));
        if(fread(buff, fSize, 1, f) > 0) {
            int place = 1;
            cur = buff[0];
            while(place <= fSize) {
                if(buff[place] == cur) {
                    curCharCount++;
                } else {
                    //solution for when we have multiple files where the last char in a file
                    //is the same as the first char in the next
                    if(place != fSize || i + 1 == argc) {
                        fwrite(&curCharCount, 4, 1, stdout);
                        fputc(cur, stdout);
                        cur = buff[place];
                        curCharCount = 1;
                    } else {
                        curCharCount+=1;
                    }
                }
                place+=1;
            }
        }
        fclose(f);
        free(buff);
    }
    return 0;
}