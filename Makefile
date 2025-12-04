CC=gcc
CFLAGS=-Wall

all: main

main: main.o aeronaves.o utils.o rotas.o
	$(CC) $(CFLAGS) -o main main.o aeronaves.o utils.o rotas.o

main.o: main.c aeronaves.h rotas.h utils.h
aeronaves.o: aeronaves.c aeronaves.h utils.h
utils.o: utils.c utils.h
rotas.o: rotas.c rotas.h

clean:
	rm -f *.o main
