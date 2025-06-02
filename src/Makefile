FLAGS=-Wall -Werror -Wextra

all: print_module documentation_module bst_create_test bst_insert_test bst_traverse_test

main: all

bst_traverse_test: bst_traverse_test.c bst.o
	gcc bst_traverse_test.c bst.o -o ../build/Quest_5

bst_insert_test: bst_insert_test.c bst.o
	gcc bst_insert_test.c bst.o -o ../build/Quest_4

bst_create_test: bst_create_test.o bst.o
	gcc bst_create_test.c bst.o -o ../build/Quest_3

bst.o: bst.c bst.h
	gcc -c bst.c

print_module: FLAGS+= -DPRINT_MODULE
print_module: main_module_entry_point.c print_module.o
	gcc $(FLAGS) main_module_entry_point.c print_module.o -o ../build/Quest_1
	rm -rf *.o

documentation_module: FLAGS+= -DDOCUMENTATION_MODULE
documentation_module: main_module_entry_point.c documentation_module.o
	gcc $(FLAGS) main_module_entry_point.c documentation_module.o -o ../build/Quest_2
	rm -rf *.o

print_module.o: print_module.c print_module.h
	gcc $(FLAGS) -c print_module.c

documentation_module.o: documentation_module.c documentation_module.h
	gcc -c documentation_module.c

clean:
	rm -rf *.o ../build/*

rebuild:
	make clean | make