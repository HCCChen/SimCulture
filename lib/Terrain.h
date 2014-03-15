#include <iostream>
#include "Calculate.h"

using namespace std;

class Terrain{
	public:
		//Construction
		Terrain(char type);
		Terrain();
		//Show Terrain Information
		bool showTerrianInfo();
		//Return Terrain Type
		char getTerrianType();
		//General world's terrain for specific type
		bool generalTerrian(char type);
	private: 
		char terrianType;
		int weatherScore;
		int resourceScore;
};
