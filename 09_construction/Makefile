main: main.o pokemon.o
	cc -o main main.o pokemon.o

main.o: main.c pokemon.h
	cc -c main.c 

pokemon.o: pokemon.c pokemon.h
	cc -c pokemon.c

.PHONY: clean run 

clean: 
	-rm  *.o

run: 
	./main
