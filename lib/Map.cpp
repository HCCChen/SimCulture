#include "Map.h"

//Generate Mountain, cycling generate
static void generateMountain(Terrain **terrain, int seedNum, int weight, int hight) {
    int i, seedX, seedY, randNum;
    //Generate Hill
    for(i = 0; i < seedNum; i++) {
        seedX = randomPositiveInt(0, (weight-1));
        seedY = randomPositiveInt(0, (hight-1));
        terrain[seedY][seedX].generalTerrian('M');
        while(true) {
            randNum = randomPositiveInt(1, 8);
            //Move direction
            if(randNum == 1 && (seedX - 1 > 0)) {
                seedX--;
            } else if(randNum == 2 && (seedX - 1 > 0) && (seedY + 1 < hight)) {
                seedX--;
                seedY++;
            } else if(randNum == 3 && (seedY + 1 < hight)) {
                seedY++;
            } else if(randNum == 4 && (seedX + 1 < weight) && (seedY + 1 < hight)) {
                seedX++;
                seedY++;
            } else if(randNum == 5 && (seedX + 1 < weight)) {
                seedX++;
            } else if(randNum == 6 && (seedX + 1 < weight) && (seedY - 1 > 0)) {
                seedX++;
                seedY--;
            } else if(randNum == 7 && (seedY - 1 > 0)) {
                seedY--;
            } else if(randNum == 8 && (seedX - 1 > 0) && (seedY - 1 > 0)) {
                seedX--;
                seedY--;
            } else { //Stop at boundry
                break;
            }
            terrain[seedY][seedX].generalTerrian('M');
            randNum = 0;
        }
    }
}

//Generate forest, linearly
static void generateForest(Terrain **terrain, int seedNum, int weight, int hight) {
    int i, seedX, seedY, randNum, cooldownCount;
    //Generate Hill
    for (i = 0, cooldownCount = 0; i < seedNum; i++, cooldownCount = 0) {
        seedX = randomPositiveInt(0, (weight-1));
        seedY = randomPositiveInt(0, (hight-1));
        terrain[seedY][seedX].generalTerrian('M');
        while (true) {
            randNum = randomPositiveInt(1, 5);
            cooldownCount++;
            //Move direction
            if (randNum == 1 && (seedX - 1 > 0)) {
                seedX--;
            } else if (randNum == 2 && (seedX - 1 > 0) && (seedY + 1 < hight)) {
                seedX--;
                seedY++;
            } else if (randNum == 3 && (seedY + 1 < hight)) {
                seedY++;
            } else if (randNum == 4 && (seedX + 1 < weight) && (seedY + 1 < hight)) {
                seedX++;
                seedY++;
            } else if (randNum == 5 && (seedX + 1 < weight)) {
                seedX++;
            } else if (randomBoolean(20 - cooldownCount, 20)) { //Stop by probability
                break;
            } else { //Stop at boundry
                break;
            }
            if (terrain[seedY][seedX].getTerrianType() == '.') {
                terrain[seedY][seedX].generalTerrian('f');
                if (seedX + 1 < weight) {
                    terrain[seedY][seedX + 1].generalTerrian('f');
                } else {
                    terrain[seedY][seedX - 1].generalTerrian('f');
                }
            }
            randNum = 0;
        }
    }
}

//Generate desert, cycling generate
static void generateDesert(Terrain **terrain, int seedNum, int weight, int hight) {
    int i, seedX, seedY, randNum;
    //Generate Hill
    for(i = 0; i < seedNum; i++) {
        seedX = randomPositiveInt(0, (weight-1));
        seedY = randomPositiveInt(0, (hight-1));
        terrain[seedY][seedX].generalTerrian('s');
        while(true) {
            randNum = randomPositiveInt(1, 8);
            //Move direction
            if(randNum == 1 && (seedX - 1 > 0)) {
                seedX--;
            } else if(randNum == 2 && (seedX - 1 > 0) && (seedY + 1 < hight)) {
                seedX--;
                seedY++;
            } else if(randNum == 3 && (seedY + 1 < hight)) {
                seedY++;
            } else if(randNum == 4 && (seedX + 1 < weight) && (seedY + 1 < hight)) {
                seedX++;
                seedY++;
            } else if(randNum == 5 && (seedX + 1 < weight)) {
                seedX++;
            } else if(randNum == 6 && (seedX + 1 < weight) && (seedY - 1 > 0)) {
                seedX++;
                seedY--;
            } else if(randNum == 7 && (seedY - 1 > 0)) {
                seedY--;
            } else if(randNum == 8 && (seedX - 1 > 0) && (seedY - 1 > 0)) {
                seedX--;
                seedY--;
            } else { //Stop at boundry
                break;
            }
            terrain[seedY][seedX].generalTerrian('s');
            randNum = 0;
        }
    }
}

Terrain** constructMap(int weight, int hight) {
    Terrain **terrain;
    int i, j, seedX, seedY, randNum;
    //Initialize basic Map
    terrain = new Terrain*[hight];
    for(i = 0; i < hight; i++) {
        terrain[i] = new Terrain[weight];
        for(j = 0; j < weight; j++) {
            terrain[i][j].generalTerrian('.');
        }
    }
    generateMountain(terrain, 2, weight, hight);
    generateForest(terrain, 2, weight, hight);
    generateDesert(terrain, 3, weight, hight);
    return terrain;
}

void showMap(Terrain **map, int weight, int hight) {
    int i, j, ret;
    ret = system("clear");
    for(i = 0; i < hight; i++){
        for(j = 0; j < weight; j++){
            cout << map[i][j].getTerrianType() << " ";
        }
        cout << endl;
    }
}

