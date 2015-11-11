#ifndef LANGUAGE_PACK
#define LANGUAGE_PACK
#include "Base.h"

using namespace std;


//Language pack name
static const string FILE_NAME_CULTURE = "culture.lang";

//Output String
struct Str_culture {
    string weather;
    string terrain;
    string resources;
    string people;
    string economic;
    string science;
    string political;
    string religion;
    string culture;
};

void loadLanguageCulture(string filePath);
//Load string information from file
bool loadLanguagePack();

#endif /* LANGUAGE_PACK */
