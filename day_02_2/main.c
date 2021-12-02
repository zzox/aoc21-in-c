#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    FILE *ptr_file;
    char *filename = "input/day_2_1.txt";

    ptr_file = fopen(filename, "r");

    if (ptr_file == NULL) {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    // initialize a string of length 20 to hold text before parsing to int
    char str[20];
    char *token;
    char words[2][10];

    int x = 0;
    int depth = 0;
    int aim = 0;
    while (fgets(str, 20, ptr_file)) {
        int i = 0;

        token = strtok(str, " ");

        // walking through strings and copying the "tokens" to the words array
        while (token != NULL) {
            strcpy(words[i], token);
            // could be done better, as this mutates the original array
            token = strtok(NULL, " ");
            i++;
        }

        int val = strtol(words[1], NULL, 10);

        if (strcmp(words[0], "down") == 0) {
            aim += val;
        }

        if (strcmp(words[0], "up") == 0) {
            aim -= val;
        }

        if (strcmp(words[0], "forward") == 0) {
            x += val;
            depth += val * aim;
        }

    }

    // %d is needed to print ints, while %s is used for strings
    printf("%d\n", x * depth);

    fclose(ptr_file);

    return 0;
}
