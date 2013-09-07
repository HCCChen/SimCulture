#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class Terrain{
	public:
		//Construction
		Terrain(int width, int height, char type);
		//Show the World Map
		bool showMap();
		//General world's terrain for specific type
		bool generalMap(char type);
	private: 
		char**	mapSpace;
		int**	mapElevation;
		int	mapWidth;
		int	mapHeight;
};
