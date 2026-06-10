CC = gcc
CFLAGS = -std=c89 -Wall -pedantic -lm

SRCS = $(wildcard *.c)
PROGS = $(SRCS:.c=)

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $< -lm

clean:
	rm -f $(PROGS)
