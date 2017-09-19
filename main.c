#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "dun_utils.h"

int findAllVertices(void);
void init_vertex_array(vertex_t *arr);
void add_vertex_to_set(vertex_t vertex);
void sort_vertex_arr(vertex_t *arr, int size);
int set_contains_vertex(sptSet_t *set, int x_position, int y_position);

void init_distances_arr(int *arr, int size);
void init_positions_arr(int *arr, int* arr2);
void init_bool_arr(bool *arr, int size);
int min_distance(int *arr, bool *set, int size);

int main(int argc, char* argv[])
{
   gen_dun();
   place_PC();
   print_dungeon();

   int array_size = findAllVertices();
   int distances[array_size + 1];
   int x_position[array_size + 1];
   int y_position[array_size + 1];
   bool set[array_size + 1];
   //int vertex_count;
   /**
   * Initialize all arrays for dijkstras
   *
   */

   init_distances_arr(distances, array_size);
   init_positions_arr(x_position, y_position);
   init_bool_arr(set, array_size + 1);

   x_position[array_size] = pc_x_position;
   y_position[array_size] = pc_y_position;
   distances[array_size] = 0;

   //find the shortes path for all vertices
   
   

   for(vertex_count = 0; vertex < (array_size); vertex_count++)
   {
       int min_v = min_distance(distances, set, array_size + 1);
       printf("min vertex found: x: %d, y:%d, distance: %d\n", x_position[min_v], y_position[min_v], distances[min_v]);

       set[min_v] = true;

       // Update dist value of the adjacent vertices of the picked vertex.

       // Update dist[v] only if is not in sptSet, there is an edge from 
       // u to v, and total weight of path from src to  v through u is 
       // smaller than current value of dist[v]
   }

   /*vertex_t vertices[array_size + 1];
   sptSet_t set;

   init_vertex_array(vertices);

   vertices[array_size].distance = 0;
   vertices[array_size].x_position = pc_x_position;
   vertices[array_size].y_position = pc_y_position;

   sort_vertex_arr(vertices, (array_size + 1));

   while(set.size != (array_size + 1))
   {

   }*/

   return 0;
}

int min_distance(int *arr, bool *set, int size)
{
    int min = INT_MAX;
    int min_indx;
    int i;

    for(i = 0; i < size; i++)
    {
        if(set[i] == false && arr[i] <= min)
        {
            min = arr[i];
            min_indx = i;
        }
    }

    return min_indx;
}

void init_bool_arr(bool *arr, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        arr[i] = false;
    }
}

int set_contains_vertex(sptSet_t *set, int x_position, int y_position)
{
    if(set->size == 0)
    {
        return 0;
    }
    
    int i;
    for(i = 0; i < set->size; i++)
    {
        int v_xPos = set->vertex[i].x_position;
        int v_yPos = set->vertex[i].y_position;

        if((x_position == v_xPos) && (y_position == v_yPos))
        {
            return 1;
        }
    }
    return 0;

}

void sort_vertex_arr(vertex_t *arr, int size)
{
    int i, j;
    for(i = 0; i < size - 1; i++)
    {
        int min_indx = i;

        for(j = i+1; j < size; j++)
        {
            int distance1 = arr[min_indx].distance;
            int distance2 = arr[j].distance;

            if(distance2 < distance1)
            {
                min_indx = j;
            }

        }

        vertex_t temp;
        temp.distance = arr[min_indx].distance;
        temp.x_position = arr[min_indx].x_position;
        temp.y_position = arr[min_indx].y_position;

        arr[min_indx].distance = arr[i].distance;
        arr[min_indx].x_position = arr[i].x_position;
        arr[min_indx].y_position = arr[i].y_position;

        arr[i].distance = temp.distance;
        arr[i].x_position = temp.x_position;
        arr[i].y_position = temp.y_position;

    }
}

void init_vertex_array(vertex_t *arr)
{
    int rows, cols;
    int array_index = 0;
    for(rows = 0; rows < dungeon_rows; rows++)
    {
        for(cols = 0; cols < dungeon_columns; cols++)
        {
            if(dungeon[rows][cols] == '.' || dungeon[rows][cols] == '#')
            {
                arr[array_index].distance = INT_MAX;
                arr[array_index].x_position = rows;
                arr[array_index].y_position = cols;
            }
        }
    }
}

void init_distances_arr(int *arr, int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        arr[i] = INT_MAX;
    }
}

void init_positions_arr(int *arr, int* arr2)
{
    int rows, cols;
    int array_index = 0;
    for(rows = 0; rows < dungeon_rows; rows++)
    {
        for(cols = 0; cols < dungeon_columns; cols++)
        {
            if(dungeon[rows][cols] == '.' || dungeon[rows][cols] == '#')
            {
                arr[array_index] = rows;
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