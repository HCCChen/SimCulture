#include "Language.h"

using namespace std;

struct Str_culture str_culture;
struct Str_UI str_UI;
struct Str_terrain str_terrain;
string tmpExternStr;


bool loadLanguagePack() {
    extern string LANGUAGE_PACKAGE_PATH;
    extern string LANGUAGE;
    string languagePath = LANGUAGE_PACKAGE_PATH + LANGUAGE + "/";
    loadLanguageCulture(languagePath);
    loadLanguageUI(languagePath);
    loadLanguageTerrain(languagePath);
    return true;
}

void loadLanguageCulture(string filePath) {
    string line, itemName, itemVariable;
    filePath += FILE_NAME_CULTURE;
    cout << filePath << endl;
    ifstream fp(filePath.c_str());
    if (fp.is_open()) {
        while (getline(fp, line)) {
            itemName = line.substr(0, line.find('='));
            itemVariable = line.substr(line.find('=') + 1, line.size());
            if (itemName.compare("parameter_weather") == 0) {
                str_culture.weather = itemVariable;
            } else if (itemName.compare("parameter_terrain") == 0) {
                str_culture.terrain = itemVariable;
            } else if (itemName.compare("parameter_resources") == 0) {
                str_culture.resources = itemVariable;
            } else if (itemName.compare("parameter_people") == 0) {
                str_culture.people = itemVariable;
            } else if (itemName.compare("parameter_economic") == 0) {
                str_culture.economic = itemVariable;
            } else if (itemName.compare("parameter_science") == 0) {
                str_culture.science = itemVariable;
            } else if (itemName.compare("parameter_political") == 0) {
                str_culture.political = itemVariable;
            } else if (itemName.compare("parameter_religion") == 0) {
                str_culture.religion = itemVariable;
            } else if (itemName.compare("parameter_culture") == 0) {
                str_culture.culture = itemVariable;
            } else if (itemName.compare("str_peopleUnit") == 0) {
                str_culture.people_unit = itemVariable;
            } else if (itemName.compare("str_totalScore") == 0) {
                str_culture.totalScore = itemVariable;
            } else if (itemName.compare("str_liveTime") == 0) {
                str_culture.liveTime = itemVariable;
            } else if (itemName.compare("str_liveTimeUnit") == 0) {
                str_culture.liveTimeUnit = itemVariable;
            } else if (itemName.compare("str_territoryCoordinate") == 0) {
                str_culture.territoryCoordinate= itemVariable;
            } else {
                cout << "Item: " << itemName << " is illegal, skip it" << endl;
            }
        }
    }
    fp.close();
}

void loadLanguageUI(string filePath) {
    string line, itemName, itemVariable;
    filePath += FILE_NAME_UI;
    cout << filePath << endl;
    ifstream fp(filePath.c_str());
    if (fp.is_open()) {
        while (getline(fp, line)) {
            itemName = line.substr(0, line.find('='));
            itemVariable = line.substr(line.find('=') + 1, line.size());
            if (itemName.compare("cmd_help") == 0) {
                str_UI.cmd_help = itemVariable;
            } else if (itemName.compare("cmd_exit") == 0) {
                str_UI.cmd_exit = itemVariable;
            } else if (itemName.compare("cmd_oneRound") == 0) {
                str_UI.cmd_oneRound = itemVariable;
            } else if (itemName.compare("cmd_multiRound") == 0) {
                str_UI.cmd_multiRound = itemVariable;
            } else if (itemName.compare("cmd_showTerrain") == 0) {
                str_UI.cmd_showTerrain = itemVariable;
            } else if (itemName.compare("cmd_default") == 0) {
                str_UI.cmd_default = itemVariable;
            } else if (itemName.compare("cmd_description_help") == 0) {
                str_UI.cmd_description_help = itemVariable;
            } else if (itemName.compare("cmd_description_exit") == 0) {
                str_UI.cmd_description_exit = itemVariable;
            } else if (itemName.compare("cmd_description_oneRound") == 0) {
                str_UI.cmd_description_oneRound = itemVariable;
            } else if (itemName.compare("cmd_description_multiRound") == 0) {
                str_UI.cmd_description_multiRound = itemVariable;
            } else if (itemName.compare("cmd_description_showTerrain") == 0) {
                str_UI.cmd_description_showTerrain = itemVariable;
            } else if (itemName.compare("cmd_description_flashScreen") == 0) {
                str_UI.cmd_description_flashScreen = itemVariable;
            } else if (itemName.compare("str_round") == 0) {
                str_UI.round = itemVariable;
            } else if (itemName.compare("str_hintToEnterCommand") == 0) {
                str_UI.hintToEnterCommand = itemVariable;
            } else if (itemName.compare("str_beforeShowCultureInfo") == 0) {
                str_UI.beforeShowCultureInfo = itemVariable;
            } else {
                cout << "Item: " << itemName << " is illegal, skip it" << endl;
            }
        }
    }
    fp.close();
}

void loadLanguageTerrain(string filePath) {
    string line, itemName, itemVariable;
    filePath += FILE_NAME_TERRAIN;
    cout << filePath << endl;
    ifstream fp(filePath.c_str());
    if (fp.is_open()) {
        while (getline(fp, line)) {
            itemName = line.substr(0, line.find('='));
            itemVariable = line.substr(line.find('=') + 1, line.size());
            if (itemName.compare("str_terrarinType") == 0) {
                str_terrain.terrainType = itemVariable;
            } else if (itemName.compare("str_weatherScore") == 0) {
                str_terrain.weatherScore = itemVariable;
            } else if (itemName.compare("str_resourceScore") == 0) {
                str_terrain.resourceScore = itemVariable;
            } else {
                cout << "Item: " << itemName << " is illegal, skip it" << endl;
            }
        }
    }
    fp.close();
}
