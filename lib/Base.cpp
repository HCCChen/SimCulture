#include "Base.h"

//Common variable
int BASE_DENOMINATOR = 1000;
int BASE_NUMERATOR = 1;

//Global Setting, initial data is define at "setting.conf"
const string CONFIG_FILE_PATH = "resources/setting.conf";
string LANGUAGE_PACKAGE_PATH;
string LANGUAGE;


int randomPositiveInt(int min, int max) {
    int randNum;
    if (min < 0 || max < 0 || min >= max) {
        return -1;
    }
    randNum = min + (rand() % (max - min + 1));
    return randNum;
}

bool randomBoolean(int numerator, int denominator) {
    int randNum, randBuf, i;
    int *selectedList;
    if (numerator < 1 || denominator < 1) {
        return false;
    }
    selectedList = new int[numerator];
    randBuf = (rand() % (denominator - numerator + 1));
    for(i = 0; i < numerator; i++) {
        selectedList[i] = randBuf + i;
    }
    randNum = (rand() % denominator);
    for(i = 0; i < numerator; i++) {
        if (selectedList[i] == randNum) {
            return true;
        }
    }
    return false;
}

string cultureIdxToString(int idx) {
    extern struct Str_culture str_culture;
    switch(idx) {
        case IDX_CULTURE_WEATHER:
            return str_culture.weather;
        break;
        case IDX_CULTURE_TERRAIN:
            return str_culture.terrain;
        break;
        case IDX_CULTURE_RESOURCES:
            return str_culture.resources;
        break;
        case IDX_CULTURE_PEOPLE:
            return str_culture.people;
        break;
        case IDX_CULTURE_ECONOMIC:
            return str_culture.economic;
        break;
        case IDX_CULTURE_SCIENCE:
            return str_culture.science;
        break;
        case IDX_CULTURE_POLITICAL:
            return str_culture.political;
        break;
        case IDX_CULTURE_RELIGION:
            return str_culture.religion;
        break;
        case IDX_CULTURE_CULTURE:
            return str_culture.culture;
        break;
    }
}

bool loadConfigFile() {
    string line, itemName, itemVariable;
    ifstream fp(CONFIG_FILE_PATH.c_str());
    if (fp.is_open()) {
        while (getline(fp, line)) {
            itemName = line.substr(0, line.find('='));
            itemVariable = line.substr(line.find('=') + 1, line.size());
            if (itemName == "languagePack_Path") {
                LANGUAGE_PACKAGE_PATH = itemVariable;
            } else if (itemName == "language") {
                LANGUAGE = itemVariable;
            } else {
                cout << "Item: " << itemName << " is illegal, skip it" << endl;
            }
        }
        fp.close();
        return true;
    }
    cout << "Load config file fail" << endl;
    return false;
}

void showConfig() {
    cout << "======== Config information ========" << endl;
    cout << "Config file path: " << CONFIG_FILE_PATH << endl;
    cout << "Language package path: " << LANGUAGE_PACKAGE_PATH << endl;
    cout << "Language: " << LANGUAGE << endl;
    cout << "====================================" << endl;
}


void log(string logContext) {
}
