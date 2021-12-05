#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_to_coords (int coords[1000][1000], int val1, int val2, int flat, int is_x_flat) {
    int inc = 1;

    if (val1 > val2) {
        inc = -1;
    }

    for (int i = val1; i != val2; i += inc) {
        if (is_x_flat) {
            coords[i][flat]++;
        } else {
            coords[flat][i]++;
        }
    }

    // account for end vals
    if (is_x_flat) {
        coords[val2][flat]++;
    } else {
        coords[flat][val2]++;
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
        if (lines[i][0] == lines[i][2]) {
            add_to_coords(coords, lines[i][1], lines[i][3], lines[i][0], 0);
        }

        if (lines[i][1] == lines[i][3]) {
            add_to_coords(coords, lines[i][0], lines[i][2], lines[i][1], 1);
        }
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
