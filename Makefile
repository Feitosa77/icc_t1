CC = gcc
CFLAGS = -O3 -mavx -march=native -Wall -I libs
TARGET = ajustePol

LIKWID_C = -DLIKWID_PERFMON -I${LIKWID_INCLUDE}
LIKWID_O = -L${LIKWID_LIB} -llikwid

all: src/main.c ir.o linear.o elimination.o point.o fitting.o utils.o
	$(CC) $(CFLAGS) $(LIKWID_C) src/main.c -o bin/$(TARGET) ir.o linear.o elimination.o point.o fitting.o utils.o -lm $(LIKWID_O)

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

utils.o: src/utils.c libs/utils.h
	$(CC) $(CFLAGS) -c src/utils.c

clean:
	rm -f *.o bin/$(TARGET)
