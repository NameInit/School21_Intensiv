FLAGS= -Wall -Werror -Wextra -std=c11

all: state_sort state_search clear_state

main: all

state_sort: state_sort.c bin_f.o data_io.o
	gcc $(FLAGS) state_sort.c bin_f.o data_io.o -o ../build/Quest_1

state_search: state_search.c bin_f.o data_io.o
	gcc $(FLAGS) state_search.c bin_f.o data_io.o -o ../build/Quest_2

clear_state: clear_state.c bin_f.o data_io.o
	gcc $(FLAGS) clear_state.c bin_f.o data_io.o -o ../build/Quest_3

bin_f.o: bin_f.c bin_f.h
	gcc $(FLAGS) -c bin_f.c

data_io.o: data_io.c data_io.h
	gcc $(FLAGS) -c data_io.c

clean: 
	rm -rf *.o ../build/Quest_1 ../build/Quest_2 ../build/Quest_3

rebuild: clean all