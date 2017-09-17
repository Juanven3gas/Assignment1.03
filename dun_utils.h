#ifndef DUN_UTILS_H
#define DUN_UTILS_H

#define dungeon_rows 21
#define dungeon_columns 80
#define num_rooms 6

char dungeon[dungeon_rows][dungeon_columns];
int rooms[num_rooms][4];
int pc_x_position;
int pc_y_position;

void print_dungeon(void);
int gen_dun(void);
void place_PC(void);

#endif