CC = gcc
CFLAGS = -O3 -mavx -march=native -Wall -I libs

TARGET = ajustePol

all: src/main.c ir.o linear.o elimination.o point.o fitting.o
	$(CC) $(CFLAGS) src/main.c -o bin/$(TARGET) ir.o linear.o elimination.o point.o fitting.o -lm

ir.o: src/ir.c libs/ir.h
	$(CC) $(CFLAGS) -c src/ir.c

linear.o: src/linear.c libs/linear.h
	$(CC) $(CFLAGS) -c src/linear.c

elimination.o: src/elimination.c libs/elimination.h
	$(CC) $(CFLAGS) -c src/elimination.c

point.o: src/point.c libs/point.h
	$(CC) $(CFLAGS) -c src/point.c

fitting.o: src/fitting.c libs/fitting.h
	$(CC) $(CFLAGS) -c src/fitting.c

clean:
	rm -f *.o bin/$(TARGET)
