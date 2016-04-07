#ifndef LANGUAGE_PACK
#define LANGUAGE_PACK
#include "Base.h"

using namespace std;


//Language pack name
static const string FILE_NAME_CULTURE = "culture.lang";
static const string FILE_NAME_UI = "UI.lang";
static const string FILE_NAME_TERRAIN = "terrain.lang";

//Output String
struct Str_culture {
    string weather;
    string terrain;
    string resources;
    string people;
    string people_unit;
    string economic;
    string science;
    string political;
    string religion;
    string culture;
    string totalScore;
    string liveTime;
    string liveTimeUnit;
    string territoryCoordinate;
};

struct Str_UI {
    string cmd_help;
    string cmd_exit;
    string cmd_oneRound;
    string cmd_multiRound;
    string cmd_showTerrain;
    string cmd_default;
    string cmd_description_help;
    string cmd_description_exit;
    string cmd_description_oneRound;
    string cmd_description_multiRound;
    string cmd_description_showTerrain;
    string cmd_description_flashScreen;
    string round;
    string hintToEnterCommand;
    string beforeShowCultureInfo;
};

struct Str_terrain {
    string terrainType;
    string weatherScore;
    string resourceScore;
};


void loadLanguageCulture(string filePath);
void loadLanguageUI(string filePath);
void loadLanguageTerrain(string filePath);
//Load string information from file
bool loadLanguagePack();

#endif /* LANGUAGE_PACK */
