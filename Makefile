sim: sim.o
	g++ sim.cpp lib/Culture.cpp lib/Terrain.cpp -O3 -o sim.o
