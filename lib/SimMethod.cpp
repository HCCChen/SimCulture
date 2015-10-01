#include "SimMethod.h"

void showMap(Terrain **map, char **cultureMap, int weight, int hight, vector<Culture> culture) {
    int i, j, ret;
    ret = system("clear");

    cout << "  ";
    for(j = 0; j < weight; j++) {
        cout << (j % 10) << " ";
    }
    cout << endl;

    for(i = 0; i < hight; i++) {
        cout << (i % 10) << " ";
        for(j = 0; j < weight; j++) {
            if(cultureMap[i][j] == '.') {
                cout << map[i][j].getTerrianShow() << " ";
            } else {
                cout << cultureMap[i][j] << " ";
            }
        }
        cout << endl;
    }
}

char** transToSymbolMap(Terrain **terrain, int weight, int hight) {
    int i, j;;
    char **map;
    map = new char*[hight];
    for (i = 0; i < hight; i++) {
        map[i] = new char[weight];
        for(j = 0; j < weight; j++) {
            map[i][j] = terrain[i][j].getTerrianType();
        }
    }
    return map;
}
