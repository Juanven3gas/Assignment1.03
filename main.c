#include <stdio.h>
#include <stdlib.h>
#include "dun_utils.h"
#include "min_heap.h"

int main(int argc, char* argv[])
{
   gen_dun();
   place_PC();
   print_dungeon();
   
   //minHeap min = initMinHeap();
   
   return 0;
}