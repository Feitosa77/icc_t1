CC = gcc
CFLAGS = -O3 -mavx -march=native -Wall -I libs

INPUT = pontos.in
OUTPUT = resultado.out
TARGET = bin/ajustePol

OBJECTS = ir.o linear.o elimination.o point.o fitting.o utils.o

LIKWID_C = -DLIKWID_PERFMON -I${LIKWID_INCLUDE}
LIKWID_O = -L${LIKWID_LIB} -llikwid

all: src/main.c $(OBJECTS)
	$(CC) $(CFLAGS) $(LIKWID_C) src/main.c -o $(TARGET) $(OBJECTS) -lm $(LIKWID_O)

%.o: src/%.c libs/%.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(TARGET) $(OUTPUT)

run: all
	./$(TARGET) < $(INPUT) > $(OUTPUT)
