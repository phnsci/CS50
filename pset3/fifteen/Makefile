CC = gcc
FLAGS = -ggdb3 -Wall -Werror -std=c11
LIBDIR = ../../lib/
INCDIR = ../../lib/

all: fifteen

fifteen: fifteen.c
	$(CC) $(FLAGS) -o fifteen fifteen.c -I $(LIBDIR) -L $(LIBDIR) -lcs50

clean: 
	rm -f *.o a.out fifteen
