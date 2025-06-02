#include <stdio.h>

#include "door_struct.h"
#define DOORS_COUNT 15

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sort_doors(doors);
    all_close(doors);
    output_doors(doors);

    return 0;
}