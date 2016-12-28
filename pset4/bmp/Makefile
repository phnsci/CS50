CC = gcc
FLAGS = -ggdb3 -Wall -Werror -std=c11

all: copy whodunit

copy: copy.c bmp.h
	$(CC) $(FLAGS) -o copy copy.c 

whoduni: whodunit.c bmp.h
	$(CC) $(FLAGS) -o whodunit whodunit.c 

clean: 
	rm -f *.o a.out whodunit copy
