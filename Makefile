CC = gcc
CFLAGS = -O3 -mavx -march=native -Wall -I libs
TARGET = ajustePol

LIKWID_C = -DLIKWID_PERFMON -I${LIKWID_INCLUDE}
LIKWID_O = -L${LIKWID_LIB} -llikwid

all: src/main.c ir.o linear.o elimination.o point.o fitting.o utils.o
	$(CC) $(CFLAGS) $(LIKWID_C) src/main.c -o bin/$(TARGET) ir.o linear.o elimination.o point.o fitting.o utils.o -lm $(LIKWID_O)

%.o: src/%.c libs/%.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o bin/$(TARGET)
