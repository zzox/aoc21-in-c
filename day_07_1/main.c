#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main () {
    FILE *ptr_file;
    char *filename = "input/day_07_1.txt";

    ptr_file = fopen(filename, "r");

    if (ptr_file == NULL) {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    char str[100000];

    int items[1000] = {0};
    int positions[1972] = {0};

    int line = 0;
    while (fgets(str, 100000, ptr_file)) {
        int i = 0;
        char *item_token;

        item_token = strtok(str, ",");
        while (item_token != NULL) {
            items[i] = strtol(item_token, NULL, 10);
            item_token = strtok(NULL, ",");
            i++;
        }
    }

    int max = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1972; j++) {
            positions[j] += abs(j - items[i]);
        }

        if (items[i] > max) {
            max = items[i];
        }
    }

    int min = INT_MAX;
    int index = -1;
    for (int i = 0; i < 1972; i++) {
        if (positions[i] < min) {
            min = positions[i];
            index = i;
        }
    }

    printf("%d\n", min);

    fclose(ptr_file);

    return 0;
}
