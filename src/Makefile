FLAGS=-Wall -Werror -Wexta

all: list_test door_struct stack_test

main: all

stack_test: stack_test.c stack.o
	gcc stack_test.c stack.o -o ../build/Quest_3 

list_test: list_test.c list.o door_struct.o
	gcc list_test.c list.o door_struct.o -o ../build/Quest_2

door_struct: dmanager_module.o door_struct.o
	gcc -o ../build/Quest_1 dmanager_module.o door_struct.o

dmanager_module.o: door_struct.o
	gcc -c dmanager_module.c

list.o: list.c list.h
	gcc -c list.c

door_struct.o: door_struct.h
	gcc -c door_struct.c

stack.o: stack.c stack.h
	gcc -c stack.c

clean:
	rm -rf a.out *.o ../build/*

