#include "Base.h"

using namespace std;

#ifndef TERRAIN
#define TERRAIN
const char SYMBOL_LAND = '.';
const char SYMBOL_MOUNTAIN = 'M';
const char SYMBOL_DESERT = 's';
const char SYMBOL_WATER = '~';
const char SYMBOL_FOREST = 't';
#endif

class Terrain{
	public:
		//Construction
		Terrain(char type);
		Terrain();
		//Show Terrain Information
		bool showTerrainInfo();
		//Return Terrain information
		char getTerrianType();
        int getWeatherScore();
        int getResourcesScore();
		string getTerrianShow();
		//General world's terrain for specific type
		bool generalTerrian(char type);
	private: 
        string terrianShow;
		char terrianType;
		int weatherScore;
		int resourceScore;
};
