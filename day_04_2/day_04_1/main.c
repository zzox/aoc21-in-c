#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bingos[10][5] = {
    {0, 1, 2, 3, 4},
    {5, 6, 7, 8, 9},
    {10, 11, 12, 13, 14},
    {15, 16, 17, 18, 19},
    {20, 21, 22, 23, 24},
    {0, 5, 10, 15, 20},
    {1, 6, 11, 16, 21},
    {2, 7, 12, 17, 22},
    {3, 8, 13, 18, 23},
    {4, 9, 14, 19, 24},
};

int found_yet (int guesses[], int index, int val) {
    for (int i = 0; i <= index; i++) {
        if (guesses[i] == val) {
            return 1;
        }
    }

    return 0;
}

int main () {
    FILE *ptr_file;
    char *filename = "input/day_04_1.txt";

    ptr_file = fopen(filename, "r");

    if (ptr_file == NULL) {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    int guesses[100];
    int boards[100][25];

    char str[1000];
    int line = -1;
    int board = -1;
    int board_item = 0;
    while (fgets(str, 1000, ptr_file)) {
        if (line == -1) {
            // split array into items
            int item = 0;
            char *item_token;

            item_token = strtok(str, ",");

            while (item_token != NULL) {
                guesses[item] = strtol(item_token, NULL, 10);
                item_token = strtok(NULL, ",");
                item++;
            }
        }

        if (line % 5 == 0) {
            board++;
            board_item = 0;
        }

        if (line > -1) {
            int item = 0;
            char *item_token;

            item_token = strtok(str, " ");

            while (item_token != NULL) {
                boards[board][board_item] = strtol(item_token, NULL, 10);
                item_token = strtok(NULL, " ");
                board_item++;
            }
        }

        line++;
    }

    for (int guess = 0; guess < 100; guess++) {
        for (int board = 0; board < 100; board++) {
            for (int b = 0; b < 10; b++) {
                if (
                    found_yet(guesses, guess, boards[board][bingos[b][0]]) &&
                    found_yet(guesses, guess, boards[board][bingos[b][1]]) &&
                    found_yet(guesses, guess, boards[board][bingos[b][2]]) &&
                    found_yet(guesses, guess, boards[board][bingos[b][3]]) &&
                    found_yet(guesses, guess, boards[board][bingos[b][4]])
                ) {
                    printf("winner\n");

                    int tot = 0;
                    for (int item = 0; item < 25; item++) {
                        if (!found_yet(guesses, guess, boards[board][item])) {
                            tot += boards[board][item];
                        }
                    }

                    printf("\n%d\n", tot * guesses[guess]);
                    fclose(ptr_file);
                    return 0;
                }
            }
        }
    }

    fclose(ptr_file);

    return 0;
}
