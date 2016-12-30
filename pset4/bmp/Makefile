CC = gcc
FLAGS = -ggdb3 -Wall -Werror -std=c11

all: copy whodunit resize

copy: copy.c bmp.h
	$(CC) $(FLAGS) -o copy copy.c 

whoduni: whodunit.c bmp.h
	$(CC) $(FLAGS) -o whodunit whodunit.c 

resize: resize.c bmp.h
	$(CC) $(FLAGS) -o resize resize.c

clean: 
	rm -f *.o a.out whodunit copy resize
