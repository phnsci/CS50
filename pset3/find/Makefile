CC = gcc
FLAGS = -ggdb3 -Wall -Werror -std=c11
LIBDIR = ../../lib/
INCDIR = ../../lib/

all: find generate

find: find.c helpers.c helpers.h 
	$(CC) $(FLAGS) -o find find.c helpers.c -I $(LIBDIR) -L $(INCDIR) -lcs50

generate: generate.c
	$(CC) $(FLAGS) -o generate generate.c -I $(LIBDIR) -L $(INCDIR) -lcs50

clean:
	rm -f *.o a.out core find generate
