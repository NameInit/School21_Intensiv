FLAGS=-Wall -Werror -Wextra

all: cipher logging_cipher

main: all

logging_cipher: cipher
	gcc $(FLAGS) -DPRINT_MODULE cipher.c shifr_caeser.o data_io.o logger.o -o ../build/logging_cipher

cipher: data_io.o shifr_caeser.o cipher.c logger.o
	gcc $(FLAGS) cipher.c shifr_caeser.o data_io.o logger.o -o ../build/cipher

data_io.o: data_io.c data_io.h
	gcc $(FLAGS) -c data_io.c

shifr_caeser.o: shifr_caeser.c shifr_caeser.h
	gcc $(FLAGS) -c shifr_caeser.c

logger.o: logger.c logger.h
	gcc $(FLAGS) -c logger.c

clean:
	rm -rf *.o ../build/cipher ../build/logging_cipher

rebuild: clean all