#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_to_coords (int coords[1000][1000], int val1, int val2, int val1_dist, int val2_dist, int inc_val1, int inc_val2) {
    int x = val1;
    int y = val2;
    for (;;) {
        coords[x][y]++;

        x += inc_val1;
        y += inc_val2;

        if (x == val1 + val1_dist && y == val2 + val2_dist) {
            return;
        }
    }
}

int main () {
    FILE *ptr_file;
    char *filename = "input/day_05_1.txt";

    ptr_file = fopen(filename, "r");

    if (ptr_file == NULL) {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    char str[64];

    int lines[500][4];

    int coords[1000][1000] = {0};

    int line = 0;
    while (fgets(str, 64, ptr_file)) {
        int item = 0;
        char *item_token;

        item_token = strtok(str, ",");
        while (item_token != NULL) {
            lines[line][item] = strtol(item_token, NULL, 10);
            item_token = strtok(NULL, ",");
            item++;
        }

        line++;
    }

    for (int i = 0; i < 500; i++) {
        int x_dist = lines[i][2] - lines[i][0];
        int y_dist = lines[i][3] - lines[i][1];

        int x_inc = 0;
        int y_inc = 0;

        if (x_dist > 0) {
            x_inc = 1;
            x_dist += 1;
        }

        if (x_dist < 0) {
            x_inc = -1;
            x_dist -= 1;
        }

        if (y_dist > 0) {
            y_inc = 1;
            y_dist += 1;
        }

        if (y_dist < 0) {
            y_inc = -1;
            y_dist -= 1;
        }

        add_to_coords(coords, lines[i][0], lines[i][1], x_dist, y_dist, x_inc, y_inc);
    }

    int tot = 0;
    for (int x = 0; x < 1000; x++) {
        for (int y = 0; y < 1000; y++) {
            if (coords[x][y] > 1) {
                tot++;
            }
        }
    }

    printf("%d\n", tot);

    fclose(ptr_file);

    return 0;
}
