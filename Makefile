CFLAGS = -Wall

all: IR.o linear.o elimination.o

IR.o: IR.c IR.h
	gcc -c IR.c $(CFLAGS)

linear.o: linear.c linear.h
	gcc -c linear.c $(CFLAGS)

elimination.o: elimination.c elimination.h
	gcc -c elimination.c $(CFLAGS)

clean:
	rm *.o
