/*
	文明模擬基本操作
	提供顯示；初始化；操作文明互動；時間流逝發展
*/

#include "Culture.h"

Culture::Culture() {
	weather = randomPositiveInt(60,100);
	terrain = randomPositiveInt(60,100);
	resources = randomPositiveInt(1,10);
	people = randomPositiveInt(5,10);
	economic = randomPositiveInt(1,10);
	science = randomPositiveInt(1,10);
	political = randomPositiveInt(60,80);
	religion = randomPositiveInt(0,100);
	culture = randomPositiveInt(1,10);
	deltaWeather = 1;
	deltaTerrain = 1;
	deltaResources = 1;
	deltaPeople = 1;
	deltaEconomic = 1;
	deltaScience = 1;
	deltaPolitical = 1;
	deltaReligion = 1;
	deltaCulture = 1;
	surviveTime = 1;
}

/*
	顯示分數
*/
void Culture::showResult() {
    int i;
    extern struct Str_culture str_culture;
	cout << str_culture.weather << ": " << weather << "/100" << endl;
	cout << str_culture.terrain << ": " << terrain << "/100" << endl;
	cout << str_culture.political << ": " << political << "/100" << endl;
	cout << str_culture.religion << ": " << religion << "/100" << endl;
	cout << str_culture.people << ": " << people << "千人" << endl;
	cout << str_culture.resources << ": " << resources << endl;
	cout << str_culture.economic << ": " << economic << endl;
	cout << str_culture.science << ": " << science << endl;
	cout << str_culture.culture << ": " << culture << endl;
	cout << "總體分數: " << "--" << endl;
	cout << "生存時間: " << surviveTime << "時" << endl;
    cout << "Territory: ";
    for(i = 0; i < territory.size(); i++) {
        cout << "(" << territory[i].x << ", " << territory[i].y << ") ";
    }
    cout << endl;
}

void Culture::simARound() {
    eventEngine.triggerSequenceEvent();
	if (weather < maxOfScore) {weather += deltaWeather;}
	if (terrain < maxOfScore) {terrain += deltaTerrain;}
	if (political < maxOfScore) {political += deltaPolitical;}
	resources += deltaResources;
	people += deltaPeople;
	economic += deltaEconomic;
	science += deltaScience;
	culture += deltaCulture;
	surviveTime += 1;

}

bool Culture::addTerritory(int x, int y) {
    Coordinate buf;
    buf.x = x;
    buf.y = y;
    territory.push_back(buf);
    return true;
}

bool Culture::removeTerritory(int x, int y) {
    unsigned i;
    Coordinate buf;
    buf.x = x;
    buf.y = y;
    for (i = 0; i < territory.size(); i++) {
        if(territory[i].x == x && territory[i].y == y) {
            territory.erase(territory.begin() + i);
            return true;
        }
    }
    return false;
}
