dun_program: main.o gen_dun.o min_heap.o
	gcc main.o gen_dun.o min_heap.o -o dun_program

main.o: main.c dun_utils.h
	gcc -Werror -Wall -ggdb main.c -c

gen_dun.o: gen_dun.c dun_utils.h
	gcc -Wall -Werror -ggdb gen_dun.c -c

min_heap.o: min_heap.c min_heap.h
	gcc -Wall -Werror -ggdb min_heap.c -c 

clean:
	rm *.o dun_program