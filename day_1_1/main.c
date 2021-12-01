#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE *ptr_file;
    char *filename = "input/day_1_1.txt";

    ptr_file = fopen(filename, "r");

    if (ptr_file == NULL) {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    // initialize a string of length 20 to hold text before parsing to int
    char str[20];

    int last = 0;
    int totals = 0;
    while (fgets(str, 20, ptr_file)) {
        // sets str with the next values from the `ptr_file`, max 20 chars
        // stops at a newline
        // implicit coercion to int, can be long
        int val = strtol(str, NULL, 10);
        if (val > last) totals++;
        last = val;
    }
    
    // subtract 1 since the first increase doens't count
    printf("%d\n", totals - 1);

    fclose(ptr_file);

    return 0;
}
