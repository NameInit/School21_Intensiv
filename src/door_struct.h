#ifndef DOOR_STRUCT_H
#define DOOR_STRUCT_H

struct door {
    int id;
    int status;
};

void output_doors(struct door* doors);
void sort_doors(struct door* doors);
void all_close(struct door* doors);
void initialize_doors(struct door* doors);

#endif
