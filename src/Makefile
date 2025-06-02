FLAGS=-Wall -Werror -Wextra

main: graph

graph: graph.c stack.o data_io.o string_lite.o
	gcc $(FLAGS) graph.c stack.o data_io.o string_lite.o -o ../build/graph

data_io.o: data_io.c data_io.h
	gcc $(FLAGS) -c data_io.c

stack.o: stack.c stack.h
	gcc $(FLAGS) -c stack.c

string_lite.o: string_lite.c string_lite.h
	gcc $(FLAGS) -c string_lite.c

clean:
	rm -rf *.o ../build/graph

rebuild:
	make clean | make