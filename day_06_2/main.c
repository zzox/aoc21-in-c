#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long sum_totals (long groups[]) {
    long totals = 0;
    for (int tot = 0; tot < 9; tot++) {
        totals += groups[tot];
    }

    return totals;
}

void zero_out (long groups[]) {
    for (int i = 0; i < 9; i++) {
        groups[i] = 0;
    }
}

int main () {
    FILE *ptr_file;
    char *filename = "input/day_06_1.txt";

    ptr_file = fopen(filename, "r");

    if (ptr_file == NULL) {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    char str[666];

    int items[300] = {};

    int line = 0;
    while (fgets(str, 666, ptr_file)) {
        int i = 0;
        char *item_token;

        item_token = strtok(str, ",");
        while (item_token != NULL) {
            items[i] = strtol(item_token, NULL, 10);
            item_token = strtok(NULL, ",");
            i++;
        }
    }

    long day_groups[9] = {0};
    long new_groups[9] = {0};
    for (int item = 0; item < 300; item++) {
        day_groups[items[item]]++;
    }

    for (int day = 0; day < 256; day++) {
        zero_out(new_groups);
        for (int group = 0; group < 9; group++) {
            if (group == 0) {
                new_groups[6] += day_groups[0];
                new_groups[8] += day_groups[0];
                new_groups[0] = 0;
            } else {
                new_groups[group - 1] += day_groups[group];
            }
        }

        memcpy(day_groups, new_groups, sizeof day_groups);
    }

    printf("%ld\n", sum_totals(day_groups));

    fclose(ptr_file);

    return 0;
}
