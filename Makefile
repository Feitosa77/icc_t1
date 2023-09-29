CC = gcc
CFLAGS = -O3 -mavx -march=native -Wall

TARGET = ajustePol

all: main.c ir.o linear.o elimination.o point.o fitting.o main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET) ir.o linear.o elimination.o point.o fitting.o -lm

ir.o: ir.c ir.h
	$(CC) $(CFLAGS) -c ir.c

linear.o: linear.c linear.h
	$(CC) $(CFLAGS) -c linear.c

elimination.o: elimination.c elimination.h
	$(CC) $(CFLAGS) -c elimination.c

point.o: point.c point.h
	$(CC) $(CFLAGS) -c point.c

fitting.o: fitting.c fitting.h
	$(CC) $(CFLAGS) -c fitting.c

clean:
	rm -f *.o $(TARGET)
