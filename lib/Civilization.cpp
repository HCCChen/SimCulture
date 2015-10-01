#include "Civilization.h"

char** constructCivilization(int weight, int hight, int numOfCulture, vector<Culture> &culture, char **terrainMap) {
    char** civilizationMap;
    int i, j, seedX, seedY, randNum;
    Culture *bufCulture;
    //Initialize basic Map
    civilizationMap = new char*[hight];
    for (i = 0; i < hight; i++) {
        civilizationMap[i] = new char[weight];
        for(j = 0; j < weight; j++) {
            civilizationMap[i][j] = '.';
        }
    }

    for (i = 0; i < numOfCulture; i++) {
        while(1) {//Avoid collision
            seedX = randomPositiveInt(0, (weight-1));
            seedY = randomPositiveInt(0, (hight-1));
            if (terrainMap[seedY][seedX] == '~') {continue;}
            if (civilizationMap[seedY][seedX] == '.') {break;}
        }
        civilizationMap[seedY][seedX] = '1' + i;
        bufCulture = new Culture();
        culture.push_back(*bufCulture);
        culture.push_back(*bufCulture);
        culture[i].addTerritory(seedX, seedY);
    }
    return civilizationMap;
}

void showCivilizationMap(char** civilizationMap, int weight, int hight) {
    int i, j, ret;
    ret = system("clear");
    for(i = 0; i < hight; i++){
        for(j = 0; j < weight; j++){
            cout << civilizationMap[i][j] << " ";
        }
        cout << endl;
    }
}

void showCultureInformation(Culture culture) {
    culture.showResult();
}
