#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char z = 48;
char o = 49;

int main () {
    FILE *ptr_file;
    char *filename = "input/day_03_1.txt";

    ptr_file = fopen(filename, "r");

    if (ptr_file == NULL) {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    // initialize a string of length 20 to hold text
    char str[20];
    char str2[20];
    // chars need to be numbers, not "0" and "1"

    char vals[1000][13];

    int j = 0;
    while (fgets(str, 20, ptr_file)) {
        strcpy(vals[i], str);
        j++;
    }

    // https://en.cppreference.com/w/cpp/string/byte/memcpy
    memcpy(dest, vals, sizeof dest);

    // find most common bit
    for (int i = 0; i < count; i++) {
        /* code */
    }
    
    while () {
        
    }




    fclose(ptr_file);

    return 0;
}

char common_bit (char[][] vals, int index, char tiebreak) {
    int one_is_most = 0;
    for (int i = 0; i < 1000; i++) {
        if (char[i][index] == o) {
            one_is_most++;
        } else {
            one_is_most--;
        }
    }

    if (one_is_most > 0) {
        return o;
    } else if (one_is_most < 0) {
        return z;
    } else {
        return tiebreak;
    }
}
