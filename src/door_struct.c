#include "door_struct.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void output_doors(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        printf("%d, %d", doors[i].id, doors[i].status);
        if ((i + 1) != DOORS_COUNT) putchar('\n');
    }
}

void sort_doors(struct door* doors) {
    int id, status;
    for (int i = 0; i < DOORS_COUNT; i++)
        for (int j = i + 1; j < DOORS_COUNT; j++)
            if (doors[i].id > doors[j].id) {
                id = doors[i].id;
                status = doors[i].status;
                doors[i].id = doors[j].id;
                doors[i].status = doors[j].status;
                doors[j].id = id;
                doors[j].status = status;
            }
}

void all_close(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) doors[i].status = 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}
