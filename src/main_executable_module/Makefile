FLAGS=-Wall -Wextra -Werror

all: main

main: main_executable_module.o data_io.o data_process.o decision.o sort.o data_stat.o
	gcc main_executable_module.o data_io.o data_process.o decision.o sort.o data_stat.o -o ../../build/Quest_3

main_executable_module.o: main_executable_module.c ../data_libs/data_io.h ../data_module/data_process.h ../yet_another_decision_module/decision.h sort.h
	gcc $(FLAGS) -c main_executable_module.c

sort.o: sort.c sort.h
	gcc $(FLAGS) -c sort.c

data_io.o: ../data_libs/data_io.c ../data_libs/data_io.h
	gcc $(FLAGS) -c ../data_libs/data_io.c

data_stat.o: ../data_libs/data_stat.c ../data_libs/data_stat.h
	gcc $(FLAGS) -c ../data_libs/data_stat.c

data_process.o: ../data_module/data_process.c ../data_module/data_process.h ../data_libs/data_stat.h
	gcc $(FLAGS) -c ../data_module/data_process.c ../data_libs/data_stat.h

decision.o:	../yet_another_decision_module/decision.c ../yet_another_decision_module/decision.h ../data_libs/data_stat.h
	gcc $(FLAGS) -c ../yet_another_decision_module/decision.c

data_stat.a: data_stat.o
	ar -rcs data_stat.a data_stat.o

build_with_static: main_executable_module.o data_io.o data_process.o decision.o sort.o data_stat.a
	gcc main_executable_module.o data_io.o data_process.o decision.o sort.o data_stat.a -o ../../build/Quest_5

data_process.so: ../data_module/data_process.c ../data_module/data_process.h ../data_libs/data_stat.h
	gcc $(FLAGS) -fPIC -c ../data_module/data_process.c ../data_libs/data_stat.h
	gcc $(FLAGS) -fPIC -c ../data_libs/data_stat.c
	gcc -shared -o data_process.so data_process.o data_stat.o

build_with_dynamic: main_executable_module.o data_io.o data_process.so decision.o sort.o data_stat.o
	gcc main_executable_module.o data_io.o data_process.so decision.o sort.o data_stat.o -o ../../build/Quest_6

clean:
	rm -rf *.a *.so *.o ../../build/*

rebuild:
	rm -rf *.a *.so *.o ../../build/* | make -f Makefile

