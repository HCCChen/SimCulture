#include "Civilization.h"

char** constructCivilization(int weight, int hight, int numOfCulture, Culture* &culture) {
    char** civilizationMap;
    int i, j, seedX, seedY, randNum;
    //Initialize basic Map
    culture = new Culture[numOfCulture];
    civilizationMap = new char*[hight];
    for (i = 0; i < hight; i++) {
        civilizationMap[i] = new char[weight];
        for(j = 0; j < weight; j++) {
            civilizationMap[i][j] = '.';
        }
    }

    //Random put culture seed into map
    for (i = 0; i < numOfCulture; i++) {
        seedX = randomPositiveInt(0, (weight-1));
        seedY = randomPositiveInt(0, (hight-1));
        civilizationMap[seedY][seedX] = '1' + i;
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
