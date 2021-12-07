#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    FILE *ptr_file;
    char *filename = "input/day_06_1.txt";

    ptr_file = fopen(filename, "r");

    if (ptr_file == NULL) {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    char str[666];

    int items[10000000] = {};
    for (int i = 0; i < 10000000; i++) {
        items[i] = -1;
    }

    int line = 0;
    while (fgets(str, 666, ptr_file)) {
        int i = 0;
        char *item_token;

        item_token = strtok(str, ",");
        while (item_token != NULL) {
            items[i] = strtol(item_token, NULL, 10);
            item_token = strtok(NULL, ",");
            i++;
        }
    }

    int index = 300;
    for (int day = 0; day < 80; day++) {
        for (int i = 0; i < 10000000; i++) {
            if (items[i] == 0) {
                items[i] = 6;
                items[index] = 9; // because it's 8 if it was present already, and we hit it once before that
                index++;
            } else {
                items[i]--;
            }
        }
    }

    printf("%d\n", index);

    fclose(ptr_file);

    return 0;
}
