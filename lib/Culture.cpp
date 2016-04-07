/*
    Basic control of Culture
    Support method: initialization, interactive with Culture, change to each cycle
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
    Display the score
*/
void Culture::showResult() {
    int i;
    extern struct Str_culture str_culture;
	cout << str_culture.weather << ": " << weather << "/100" << endl;
	cout << str_culture.terrain << ": " << terrain << "/100" << endl;
	cout << str_culture.political << ": " << political << "/100" << endl;
	cout << str_culture.religion << ": " << religion << "/100" << endl;
	cout << str_culture.people << ": " << people << " " << str_culture.people_unit << endl;
	cout << str_culture.resources << ": " << resources << endl;
	cout << str_culture.economic << ": " << economic << endl;
	cout << str_culture.science << ": " << science << endl;
	cout << str_culture.culture << ": " << culture << endl;
	cout << str_culture.totalScore << ": " << "--" << endl;
	cout << str_culture.liveTime << ": " << surviveTime << " " << str_culture.liveTimeUnit << endl;
    cout << str_culture.territoryCoordinate << ": ";
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

vector<Coordinate> Culture::getTerritory() {
    return territory;
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

double Culture::getWeatherScore() {
    return weather;
}

double Culture::getTerrainScore() {
    return terrain;
}

double Culture::getResourcesScore() {
    return resources;
}

double Culture::getPeopleScore() {
    return people;
}

double Culture::getEconomicScore() {
    return economic;
}

double Culture::getScienceScore() {
    return science;
}

double Culture::getPoliticalScore() {
    return political;
}

double Culture::getReligionScore() {
    return religion;
}

double Culture::getCultureScore() {
    return culture;
}
