main : main.o euler.o
	cc -o main main.o euler.o

main.o : main.c euler.h
	cc -c main.c

euler.o : euler.c euler.h
	cc -c euler.c 

.PHONY: clean 

clean: 
	-rm *.o

run: 
	./main
