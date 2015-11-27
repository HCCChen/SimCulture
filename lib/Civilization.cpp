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
    ret = clearScreen();
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

void doCivilizationBehavior(Culture culture) {
    extern Terrain **terrain;
    extern const int BASE_DENOMINATOR;
    const int ACTION_EXTEND_TERRAIN = 0;
    const int ACTION_REDUCE_TERRAIN = 1;
    double people = culture.getPeopleScore();
    double resources = culture.getResourcesScore();
    double political = culture.getPoliticalScore();
    double weather = culture.getWeatherScore();
    int behavior, positiveScore = 0, negativeScore = 0;
    vector<Coordinate> territory = culture.getTerritory();
    int i;
    //Judge for each territory
    for (i = 0; i < territory.size(); i++) {
        cout << "(" << territory[i].x << ", " << territory[i].y << ") ";
        cout << terrain[territory[i].x][territory[i].y].getWeatherScore() << endl;
    }
    return;

    //Judge the behavior
    if (resources <= 60) {
        positiveScore += resources;
    } else {
        negativeScore += resources;
    }
    if (political <= 60) {
        positiveScore += political;
    } else {
        negativeScore += political;
    }
    if (weather <= 60) {
        positiveScore += weather;
    } else {
        negativeScore += weather;
    }
/*
    cout << "\tPeople score: " << people << endl;
    cout << "\tResources score: " << resources << endl;
    cout << "\tPolitical score: " << political << endl;
    cout << "\tWeather score: " << weather << endl;
    cout << "\tPositiveScore: " << positiveScore << " & NegativeScore: " << negativeScore << endl;
*/
    cout << territory[0].x << ", " << territory[0].y << " ";
    cout << terrain[territory[0].x][territory[0].y].getWeatherScore() << endl;
    cout << "\tThen result of extend judge: " << randomBoolean(people, BASE_DENOMINATOR) << endl;
    //Do the behavior
    if (randomBoolean(people + positiveScore, BASE_DENOMINATOR + negativeScore)) {
        behavior = ACTION_EXTEND_TERRAIN;
    }
}
