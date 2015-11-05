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
	cout << "氣候分數: " << weather << "/100" << endl;
	cout << "地形分數: " << terrain << "/100" << endl;
	cout << "政治分數: " << political << "/100" << endl;
	cout << "宗教分數: " << religion << "/100" << endl;
	cout << "人口分數: " << people << "千人" << endl;
	cout << "資源分數: " << resources << endl;
	cout << "經濟分數: " << economic << endl;
	cout << "科技分數: " << science << endl;
	cout << "文化分數: " << culture << endl;
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
