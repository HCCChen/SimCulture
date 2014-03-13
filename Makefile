CC = g++
CFLAGS = -O2 -std=c++0x

all: sim.o Culture.o Terrain.o Calculate.o
	${CC} sim.cpp Culture.o Terrain.o Calculate.o ${CFLAGS} -o sim.out
	rm *.o
Culture.o: lib/Culture.cpp
	${CC} lib/Culture.cpp -c
Terrain.o: lib/Terrain.cpp
	${CC} lib/Terrain.cpp -c
Calculate.o: lib/Calculate.cpp
	${CC} lib/Calculate.cpp -c