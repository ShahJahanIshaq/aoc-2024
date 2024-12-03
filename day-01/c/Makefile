objects = part1.o part2.o

all: $(objects)

part1.o: part1.c
	gcc-14 -Wall -o part1.o part1.c -O3

part2.o: part2.c
	gcc-14 -Wall -o part2.o part2.c -O3

clean:
	rm -f *.o
