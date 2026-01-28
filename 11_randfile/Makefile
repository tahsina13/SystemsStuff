main: main.o
	cc -o main main.c

main.o: main.c
	cc -c main.c

.PHONY: clean run 

clean: 
	-rm *.o

run: 
	./main
