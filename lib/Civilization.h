#include "Calculate.h"
#include "Culture.h"

//Initialize Culture and generate the seed of culture
char** constructCivilization(int weight, int hight, int numOfCulture, Culture* &culture);
//Show Civilization Map
void showCivilizationMap(char** civilizationMap, int weight, int hight);
//Show given culture information
void showCultureInformation(Culture culture);