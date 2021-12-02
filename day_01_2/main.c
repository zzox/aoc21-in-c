#include <stdio.h>
#include <stdlib.h>

// function declaration with return type and type params
void shift_window (int window_vals[], int new_val);

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

    int vals[] = { 0, 0, 0 };
    int last = 0;
    int totals = 0;
    while (fgets(str, 20, ptr_file)) {
        // sets str with the next values from the `ptr_file`, max 20 chars,
        // stops at a newline
        // implicit coercion to int, can be long
        int val = strtol(str, NULL, 10);
        shift_window(vals, val);
        int tot = vals[0] + vals[1] + vals[2];
        if (tot > last) totals++;
        last = tot;
    }
    
    // subtract 3 since the first day plus two increases don't count
    printf("%d\n", totals - 3);

    fclose(ptr_file);

    return 0;
}

// function definition after declaration
void shift_window (int window_vals[], int new_val) {
    window_vals[0] = window_vals[1];
    window_vals[1] = window_vals[2];
    window_vals[2] = new_val;
}
