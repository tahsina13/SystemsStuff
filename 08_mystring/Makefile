main: main.o mystring.o
	cc -o main main.o mystring.o

main.o: main.c mystring.h
	cc -c main.c

mystring.o: mystring.c mystring.h
	cc -c mystring.c

.PHONY: clean 

clean: 
	-rm *.o

run: 
	./main
