#include "lib/SimMethod.h"

int commandHandler(char cmd, Terrain **terrain);
void commandCatcher(char &cmd);

//For testing
const int DEFAULT_NUMBER_OF_CULTURE = 3;
const int DEFAULT_WEIGHT_OF_MAP = 5;
const int DEFAULT_HIGHT_OF_MAP = 5;

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
            cout << "Round: " << goingRound << endl;
            //Delta of Culture
            //Cross culture event
            for(i = 0; i < numberOfCulture; i++) {
                //Regular develope & event happened
                culture[i].simARound();
                //AI behavior
                //Basic behavior
                doCivilizationBehavior(culture[i]);
                //Show result
                cout << "Show the result of culture " << i << ": " << endl;
                culture[i].showResult();
            }
            //Event of Culture
            //Expansion/Reduce of land
            goingRound--;
            sleep(1);
        }
    }
    return 0;
}

void commandCatcher(char &cmd) {
    cout << "Please enter the command: ";
    cin >> cmd;
}

int commandHandler(char cmd, Terrain **terrain) {
    int intBuf = 0, x = 0, y = 0, ret = 0;
    while(1) {
        switch(cmd) {
            case 'h':
                cout << "Show command list: " << endl;
                commandCatcher(cmd);
                continue;
                break;
            case 'E':
                cout << "Exit the program" << endl;
                return -1;
                break;
            case 'g':
                cout << "Go to next round" << endl;
                return 1;
                break;
            case 'G':
                cout << "Go to next N round" << endl << "n: ";
                cin >> intBuf;
                return intBuf;
                break;
            case 'v':
                cout << "Please input x and y value:" << endl;
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
                cout << "Invaild command, please try again: ";
                cin >> cmd;
                continue;
        }
    }
}
