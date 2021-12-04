#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char *zero = "0";

    // input string width
    int items = 12;
    // words need ti be initialized with zeros since when it's
    // not initialized with a zero we get reverse-overflow type errors when doing --;
    int words[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    while (fgets(str, 20, ptr_file)) {
        for (int i = 0; i < items; i++) {
            if (str[i] == zero[0]) {
                words[i]--;
            } else {
                words[i]++;
            }
        }
    }

    // chars need to be numbers, not "0" and "1"
    char z = 48;
    char o = 49;

    // length of the string plus null terminating byte
    char gamma_string[13];
    char epsilon_string[13];
    for (int i = 0; i < items; i++) {
        if (words[i] > 0) {
            gamma_string[i] = o;
            epsilon_string[i] = z;
        } else {
            gamma_string[i] = z;
            epsilon_string[i] = o;
        }
    }

    gamma_string[12] = '\0';
    epsilon_string[12] = '\0';

    // %ld is needed to print longs, while %s is used for strings
    printf("%ld\n", strtol(gamma_string, NULL, 2) * strtol(epsilon_string, NULL, 2));

    fclose(ptr_file);

    return 0;
}
