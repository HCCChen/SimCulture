#include "Base.h"

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
    switch(idx) {
        case IDX_CULTURE_WEATHER:
            return "Weather";
        break;
        case IDX_CULTURE_TERRAIN:
            return "Terrain";
        break;
        case IDX_CULTURE_RESOURCES:
            return "Resources";
        break;
        case IDX_CULTURE_PEOPLE:
            return "People";
        break;
        case IDX_CULTURE_ECONOMIC:
            return "Economic";
        break;
        case IDX_CULTURE_SCIENCE:
            return "Science";
        break;
        case IDX_CULTURE_POLITICAL:
            return "Political";
        break;
        case IDX_CULTURE_RELIGION:
            return "Religion";
        break;
        case IDX_CULTURE_CULTURE:
            return "Culture";
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

bool loadLanguagePack() {
    return true;
}

void log(string logContext) {
}
