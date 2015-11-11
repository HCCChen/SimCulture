#include "Language.h"

using namespace std;

struct Str_culture str_culture;
string tmpExternStr;


bool loadLanguagePack() {
    extern string LANGUAGE_PACKAGE_PATH;
    extern string LANGUAGE;
    string languagePath = LANGUAGE_PACKAGE_PATH + LANGUAGE + "/";
    loadLanguageCulture(languagePath);
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
            } else {
                cout << "Item: " << itemName << " is illegal, skip it" << endl;
            }
        }
    }
    fp.close();
}
