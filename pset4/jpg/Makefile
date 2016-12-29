CC = gcc
FLAGS = -ggdb3 -Wall -Werror -std=c11

all: recover

recover: recover.c jpg.h
	$(CC) $(FLAGS) -o recover recover.c jpg.h

clean: 
	rm -f *.o a.out recover
