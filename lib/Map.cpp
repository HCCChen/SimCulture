#include "Map.h"

//Debug for show generate process
static void showGenerateStep(Terrain **map, int weight, int hight) {
    char buf;
    showTerrainMap(map, weight, hight);
    sleep(2);
}

//Generate next seed by probability, return it is at boundary or not
static bool generateNextSeed(int &seedX, int &seedY, int weight, int hight, int type) {
    int randNum;
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
        return true;
    }
    return false;
}

//Generate Mountain, cycling generate
static void generateMountain(Terrain **terrain, int seedNum, int weight, int hight) {
    int i, seedX, seedY;
    //Generate Hill
    for(i = 0; i < seedNum; i++) {
        seedX = randomPositiveInt(0, (weight-1));
        seedY = randomPositiveInt(0, (hight-1));
        terrain[seedY][seedX].generalTerrian(SYMBOL_MOUNTAIN);
        while(true) {
            if (!generateNextSeed(seedX, seedY, weight, hight, 0)) {
                terrain[seedY][seedX].generalTerrian(SYMBOL_MOUNTAIN);
            } else {
                break;
            }
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
        terrain[seedY][seedX].generalTerrian(SYMBOL_FOREST);
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
            } else { //Stop at boundry
                break;
            }
            if (!randomBoolean(100 - cooldownCount, 100)) { //Stop by probability
                break;
            }
            if (terrain[seedY][seedX].getTerrianType() == SYMBOL_LAND) {
                terrain[seedY][seedX].generalTerrian(SYMBOL_FOREST);
                if (seedX + 1 < weight) {
                    terrain[seedY][seedX + 1].generalTerrian(SYMBOL_FOREST);
                } else {
                    terrain[seedY][seedX - 1].generalTerrian(SYMBOL_FOREST);
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
        terrain[seedY][seedX].generalTerrian(SYMBOL_DESERT);
        while(true) {
            if (!generateNextSeed(seedX, seedY, weight, hight, 0)) {
                terrain[seedY][seedX].generalTerrian(SYMBOL_DESERT);
            } else {
                break;
            }
        }
    }
}

//Generate Water, cycling generate
static void generateWater(Terrain **terrain, int seedNum, int weight, int hight) {
    int i, seedX, seedY, randNum;
    //Generate Hill
    for(i = 0; i < seedNum; i++) {
        seedX = randomPositiveInt(0, (weight-1));
        seedY = randomPositiveInt(0, (hight-1));
        terrain[seedY][seedX].generalTerrian(SYMBOL_WATER);
        while(true) {
            if (!generateNextSeed(seedX, seedY, weight, hight, 0)) {
                if (terrain[seedY][seedX].getTerrianType() == SYMBOL_LAND) {
                    terrain[seedY][seedX].generalTerrian(SYMBOL_WATER);
                    if (seedX + 1 < weight) {
                        terrain[seedY][seedX + 1].generalTerrian(SYMBOL_WATER);
                    } else {
                        terrain[seedY][seedX - 1].generalTerrian(SYMBOL_WATER);
                    }
                }
            } else {
                break;
            }
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
            terrain[i][j].generalTerrian(SYMBOL_LAND);
        }
    }
    generateMountain(terrain, 2, weight, hight);
    generateForest(terrain, 2, weight, hight);
    generateDesert(terrain, 3, weight, hight);
    generateWater(terrain, 10, weight, hight);
    return terrain;
}

void showTerrainMap(Terrain **map, int weight, int hight) {
    int i, j, ret;
    ret = system("clear");
    for(i = 0; i < hight; i++){
        for(j = 0; j < weight; j++) {
            cout << map[i][j].getTerrianShow() << " ";
        }
        cout << endl;
    }
}
