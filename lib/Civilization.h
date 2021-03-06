#include "Base.h"
#include "Culture.h"
#include "Map.h"

//Initialize Culture and generate the seed of culture
char** constructCivilization(int weight, int hight, int numOfCulture, vector<Culture> &culture, char **terrainMap);
//Show Civilization Map
void showCivilizationMap(char** civilizationMap, int weight, int hight);
//Show given culture information
void showCultureInformation(Culture culture);
//Basic behavior of culture in each round
//Result: Expansion/Reduce territory automatically
void doCivilizationBehavior(Culture culture);
