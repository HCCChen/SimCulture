CC = g++
CFLAGS = -O2 -std=c++0x
INCLUDE = Culture.o Terrain.o Base.o Map.o Civilization.o SimMethod.o Event.o Language.o
TARGET = -o sim.out

all: sim.o Culture.o Terrain.o Base.o Map.o Civilization.o SimMethod.o Event.o Language.o
	${CC} sim.cpp ${INCLUDE} ${CFLAGS} ${TARGET}
	rm *.o
Culture.o: lib/Culture.cpp
	${CC} lib/Culture.cpp -c
Terrain.o: lib/Terrain.cpp
	${CC} lib/Terrain.cpp -c
Base.o: lib/Base.cpp
	${CC} lib/Base.cpp -c
Map.o: lib/Map.cpp
	${CC} lib/Map.cpp -c
Civilization.o: lib/Civilization.cpp
	${CC} lib/Civilization.cpp -c
SimMethod.o: lib/SimMethod.cpp
	${CC} lib/SimMethod.cpp -c
Event.o: lib/Event.cpp
	${CC} lib/Event.cpp -c
Language.o: lib/Language.cpp
	${CC} lib/Language.cpp -c
clear.o:
	rm *.o
