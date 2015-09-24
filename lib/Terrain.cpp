#include "Terrain.h"

Terrain::Terrain() {
	generalTerrian(SYMBOL_LAND);
}

Terrain::Terrain(char type) {
	generalTerrian(type);
}

bool Terrain::showTerrainInfo() {
	cout << endl << "==================" << endl;
	cout << "地形種類：" << terrianType << endl;
	cout << "氣候分數：" << weatherScore << endl;
	cout << "資源分數：" << resourceScore << endl;
	cout << "==================" << endl;
	return true;
}

char Terrain::getTerrianType() {
	return terrianType;	
}

string Terrain::getTerrianShow() {
    return terrianShow;
}

bool Terrain::generalTerrian(char type) {
	terrianType = type;
    switch (type) {
        case SYMBOL_LAND:
            terrianShow = LIGHT_GREEN + type;
        break;
        case SYMBOL_MOUNTAIN:
            terrianShow = LIGHT_CYAN + type;
        break;
        case SYMBOL_FOREST:
            terrianShow = NORMAL_GREEN + type;
        break;
        case SYMBOL_DESERT:
            terrianShow = NORMAL_YELLOW + type;
        break;
        case SYMBOL_WATER:
            terrianShow = LIGHT_BLUE + type;
        break;
    }
    terrianShow += END_COLOR;
	weatherScore = randomPositiveInt(40, 90);
	resourceScore = randomPositiveInt(40, 90);
	return true;
}
