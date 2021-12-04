#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char z = 48;
char o = 49;

char loser[13] = "loser";

char common_bit (char vals[][13], int index, char tiebreak);
char least_common_bit (char vals[][13], int index, char tiebreak);

// bad code!
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
    // chars need to be numbers, not "0" and "1"

    char vals[1000][13];

    int j = 0;
    while (fgets(str, 20, ptr_file)) {
        strcpy(vals[j], str);
        j++;
    }

    char dest_gamma[1000][13];
    int gamma_rate = -1;
    // https://en.cppreference.com/w/cpp/string/byte/memcpy
    memcpy(dest_gamma, vals, sizeof dest_gamma);

    int try = 0;
    int losers = 0;
    char winning_bit = o;
    while (1) {
        int it = try % 12;

        winning_bit = common_bit(dest_gamma, it, o);

        for (int k = 0; k < 1000; k++) {
            if (losers == 999 && strcmp(dest_gamma[k], loser) != 0) {
                printf("%s\n", dest_gamma[k]);
                gamma_rate = strtol(dest_gamma[k], NULL, 2);
            }

            if (strcmp(dest_gamma[k], loser) != 0 && dest_gamma[k][it] != winning_bit) {
                strcpy(dest_gamma[k], loser);
                losers++;
            }
        }

        try++;

        if (try == 1000 || gamma_rate != -1) {
            printf("%d\n", gamma_rate);
            break;
        }
    }

    char dest_epsilon[1000][13];
    int epsilon_rate = -1;
    // https://en.cppreference.com/w/cpp/string/byte/memcpy
    memcpy(dest_epsilon, vals, sizeof dest_epsilon);

    try = 0;
    losers = 0;
    winning_bit = z;
    while (1) {
        int it = try % 12;

        winning_bit = least_common_bit(dest_epsilon, it, z);

        for (int k = 0; k < 1000; k++) {
            if (losers == 999 && strcmp(dest_epsilon[k], loser) != 0) {
                printf("%s\n", dest_epsilon[k]);
                epsilon_rate = strtol(dest_epsilon[k], NULL, 2);
            }

            if (strcmp(dest_epsilon[k], loser) != 0 && dest_epsilon[k][it] != winning_bit) {
                strcpy(dest_epsilon[k], loser);
                losers++;
            }
        }

        try++;

        if (try == 1000 || epsilon_rate != -1) {
            printf("%d\n", epsilon_rate);
            break;
        }
    }

    printf("\n\n%d\n", epsilon_rate * gamma_rate);

    fclose(ptr_file);

    return 0;
}

char common_bit (char vals[][13], int index, char tiebreak) {
    int one_is_most = 0;
    for (int i = 0; i < 1000; i++) {
        if (strcmp(vals[i], loser) != 0) {
            if (vals[i][index] == o) {
                one_is_most++;
            } else {
                one_is_most--;
            }
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

char least_common_bit (char vals[][13], int index, char tiebreak) {
    int one_is_most = 0;
    for (int i = 0; i < 1000; i++) {
        if (strcmp(vals[i], loser) != 0) {
            if (vals[i][index] == o) {
                one_is_most++;
            } else {
                one_is_most--;
            }
        }
    }

    if (one_is_most > 0) {
        return z;
    } else if (one_is_most < 0) {
        return o;
    } else {
        return tiebreak;
    }
}
