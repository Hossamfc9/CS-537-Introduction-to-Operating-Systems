#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valid_string(char* str) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == '\'' || (str[i] >= '0' && str[i] <= '9')) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char* argv[]) {
    if(argc != 4) {
        printf("across: invalid number of arguments\n");
        exit(1);
    }

    char *substr, *filename = "/usr/share/dict/words";
    substr = argv[1];
    int start = atoi(argv[2]), size = atoi(argv[3]);
    int length = strlen(substr);

    FILE* fp = fopen(filename, "r");

    char* temp = malloc(256);
    int check = 0;
    while(fgets(temp, 256, fp)) {
        int ok = 1;
        if(strlen(temp) - 1 == size && valid_string(temp)) {
            for(int i = start, cnt = 0; cnt < length; ++i, ++cnt) {
                if(temp[i] != substr[cnt]) {
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                printf("%s", temp);
                check = 1;
            }
        }
    }
    
    free(temp);
    fclose(fp);

    if(!check) {
        printf("across: invalid position\n");
        exit(1);
    }
    return 0;
}