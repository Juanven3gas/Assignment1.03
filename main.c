#include <stdio.h>
#include <stdlib.h>
#include "dun_utils.h"


int main(int argc, char* argv[])
{
   gen_dun();
   place_PC();
   print_dungeon();
   
   return 0;
}