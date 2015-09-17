#include "Terrain.h"

Terrain::Terrain(){
	generalTerrian('.');
}

Terrain::Terrain(char type){
	generalTerrian(type);
}

bool Terrain::showTerrianInfo(){
	cout << endl << "==================" << endl;
	cout << "地形種類：" << terrianType << endl;
	cout << "氣候分數：" << weatherScore << endl;
	cout << "資源分數：" << resourceScore << endl;
	cout << "==================" << endl;
	return true;
}

char Terrain::getTerrianType(){
	return terrianType;	
}

bool Terrain::generalTerrian(char type){
	terrianType = type;
	weatherScore = randomPositiveInt(40, 90);
	resourceScore = randomPositiveInt(40, 90);
	return true;
}
