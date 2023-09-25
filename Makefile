#Makefile temporario...

CFLAGS = -Wall

all: main.c ir.o linear.o elimination.o point.o fitting.o main.c
	gcc main.c ir.o linear.o elimination.o point.o fitting.o $(CFLAGS) -lm

ir.o: ir.c ir.h
	gcc -c ir.c $(CFLAGS)

linear.o: linear.c linear.h
	gcc -c linear.c $(CFLAGS)

elimination.o: elimination.c elimination.h
	gcc -c elimination.c $(CFLAGS)

point.o: point.c point.h
	gcc -c point.c $(CFLAGS)

fitting.o: fitting.c fitting.h
	gcc -c fitting.c $(CFLAGS)

clean:
	rm *.o
purge: clean
	rm -f a.out
