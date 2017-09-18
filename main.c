#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "dun_utils.h"
#include "min_heap.h"

int findAllVertices(void);
void init_positions_array(char *arr1, char *arr2);

int main(int argc, char* argv[])
{
   gen_dun();
   place_PC();
   print_dungeon();

   int array_size = findAllVertices();
   printf("vertices found:%d\n", array_size);

   char x_positions[array_size + 1];
   char y_positions[array_size + 1];

   init_positions_array(x_positions, y_positions);

   //minHeap min = initMinHeap();
   
   return 0;
}

void init_positions_array(char *arr1, char *arr2)
{
    int rows, cols;
    int array_index = 0;
    for(rows = 0; rows < dungeon_rows; rows++)
    {
        for(cols = 0; cols < dungeon_columns; cols++)
        {
            if(dungeon[rows][cols] == '.' || dungeon[rows][cols] == '@' || dungeon[rows][cols] == '#')
            {
                arr1[array_index] = rows;
                arr2[array_index] = cols;
                array_index++;
            }
        }
    }
}

int findAllVertices(void)
{
    int rows, cols;
    int vertices_found = 0;
    for(rows = 0; rows < dungeon_rows; rows++)
    {
        for(cols = 0; cols < dungeon_columns; cols++)
        {
            if(dungeon[rows][cols] == '.' || dungeon[rows][cols] == '#')
            {
                vertices_found++;
            }
        }
    }

    return vertices_found;
}