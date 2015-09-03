#include <unistd.h>
#include "lib/Culture.h"
#include "lib/Terrain.h"
#include "lib/Calculate.h"

int commandHandler(char cmd);
bool commandCatcher(char* cmd);
void showMap(Terrain **map);

int main(int argc, char* argv[]){
    srand((unsigned)time(NULL));
    Terrain **terrain;
    int i, j, ret, goingRound = 0;
    char cmd;
    Culture culture[3];

    //Create Map
    terrain = new Terrain*[20];
    for(i = 0; i < 20; i++){
        terrain[i] = new Terrain[20];
        for(j = 0; j < 20; j++){
            terrain[i][j].generalTerrian('.');
        }
    }
    cout << "Map gereate finish" << endl;

    while(1) {
        //Show map
        showMap(terrain);
        //Handle user command
        if (goingRound == 0) {
            commandCatcher(&cmd);
            ret = commandHandler(cmd);
            if (ret == -1) {break;}
            else if (ret == 1) {continue;}
            else if (ret > 1) {
                goingRound = ret;
            }
        }
        else {
            cout << "Round: " << goingRound << endl;
            goingRound--;
            sleep(1);
        }
    }
    return 0;
}

void showMap(Terrain **map) {
    int i, j, ret;
    ret = system("clear");
    for(i = 0; i < 20; i++){
        for(j = 0; j < 20; j++){
            cout << map[i][j].getTerrianType() << " ";
        }
        cout << endl;
    }
}

bool commandCatcher(char* cmd) {
    cout << "Please enter the command: ";
    cin >> cmd;
    return true;
}

int commandHandler(char cmd) {
    int intBuf = 0;
    while(1) {
        switch(cmd) {
            case 'h':
                cout << "Show command list: " << endl;
                commandCatcher(&cmd);
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
            default:
                cout << "Invaild command, please try again: ";
                cin >> cmd;
                continue;
        }
    }
}
