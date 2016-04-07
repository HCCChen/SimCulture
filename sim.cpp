#include "lib/SimMethod.h"
#include "lib/Base.h"

int commandHandler(char cmd, Terrain **terrain);
void commandCatcher(char &cmd);

//For testing
const int DEFAULT_NUMBER_OF_CULTURE = 3;
const int DEFAULT_WEIGHT_OF_MAP = 5;
const int DEFAULT_HIGHT_OF_MAP = 5;
extern struct Str_UI str_UI;

int main(int argc, char* argv[]){
    srand((unsigned)time(NULL));
    extern Terrain **terrain;
    char **cultureMap;
    char **terrainMap;
    int i, j, ret, goingRound = 0;
    int mapWeight = DEFAULT_WEIGHT_OF_MAP, mapHight = DEFAULT_HIGHT_OF_MAP, numberOfCulture = DEFAULT_NUMBER_OF_CULTURE;
    char cmd;
    vector<Culture> culture;

    //Initialize
    loadConfigFile();
    loadLanguagePack();

    terrain = constructMap(mapWeight, mapHight);
    terrainMap = transToSymbolMap(terrain, mapWeight, mapHight);
    cultureMap = constructCivilization(mapWeight, mapHight, numberOfCulture, culture, terrainMap);
    showMap(terrain, cultureMap, mapWeight, mapHight, culture);
    while(1) {//Simulator
        //Show map
        showMap(terrain, cultureMap, mapWeight, mapHight, culture);
        //Handle user command
        if (goingRound == 0) {
            commandCatcher(cmd);
            ret = commandHandler(cmd, terrain);
            if (ret == -1) {break;}
            else if (ret == -2) {continue;}
            else if (ret > 0) {
                goingRound = ret;
            }
        }
        else {//Calculate each round delta
            cout << str_UI.round << ": " << goingRound << endl;
            //Delta of Culture
            //Cross culture event
            for(i = 0; i < numberOfCulture; i++) {
                //Regular develope & event happened
                culture[i].simARound();
                //AI behavior
                //Basic behavior
                doCivilizationBehavior(culture[i]);
                //Show result
                cout << endl << str_UI.beforeShowCultureInfo << " " << i << ": " << endl;
                culture[i].showResult();
            }
            //Event of Culture
            //Expansion/Reduce of land
            goingRound--;
            sleep(1);
        }
        cout << endl;
    }
    return 0;
}

void commandCatcher(char &cmd) {
    cout << str_UI.hintToEnterCommand << ": ";
    cin >> cmd;
}

int commandHandler(char cmd, Terrain **terrain) {
    int intBuf = 0, x = 0, y = 0, ret = 0;
    while(1) {
        switch(cmd) {
            case 'h':
                cout << str_UI.cmd_help << ": " << endl;
                cout << "\t" << str_UI.cmd_description_help << endl;
                cout << "\t" << str_UI.cmd_description_exit << endl;
                cout << "\t" << str_UI.cmd_description_oneRound << endl;
                cout << "\t" << str_UI.cmd_description_multiRound << endl;
                cout << "\t" << str_UI.cmd_description_showTerrain << endl;
                cout << "\t" << str_UI.cmd_description_flashScreen << endl;
                commandCatcher(cmd);
                continue;
                break;
            case 'E':
                cout << str_UI.cmd_exit << endl;
                return -1;
                break;
            case 'g':
                cout << str_UI.cmd_oneRound << endl;
                return 1;
                break;
            case 'G':
                cout << str_UI.cmd_multiRound << endl << "n: ";
                cin >> intBuf;
                return intBuf;
                break;
            case 'v':
                cout << str_UI.cmd_showTerrain << endl;
                cout << "x: ";
                cin >> x;
                cout << "y: ";
                cin >> y;
                terrain[y][x].showTerrainInfo();
                commandCatcher(cmd);
                continue;
                break;
            case 'f':
                return -2;
                break;
            //Below is debug command
            case 'd':
                commandCatcher(cmd);
                continue;
                break;
            default:
                cout << str_UI.cmd_default << ": ";
                cin >> cmd;
                continue;
        }
    }
}
