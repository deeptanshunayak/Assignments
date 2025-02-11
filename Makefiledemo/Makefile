


CC = gcc

CFLAGS = -Wall -g

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

all:main

main:$(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) main
