#include "lib/Culture.h"
#include "lib/Map.h"

int commandHandler(char cmd, Terrain **terrain);
bool commandCatcher(char* cmd);

int main(int argc, char* argv[]){
    srand((unsigned)time(NULL));
    Terrain **terrain;
    int i, j, ret, goingRound = 0;
    char cmd;
    Culture culture[3];
    terrain = constructMap(40, 20);

    while(1) {
        //Show map
        terrain = constructMap(40, 20);
        showMap(terrain, 40, 20);
        //Handle user command
        if (goingRound == 0) {
            commandCatcher(&cmd);
            ret = commandHandler(cmd, terrain);
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

bool commandCatcher(char* cmd) {
    cout << "Please enter the command: ";
    cin >> cmd;
    return true;
}

int commandHandler(char cmd, Terrain **terrain) {
    int intBuf = 0, x = 0, y = 0, ret = 0;
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
            case 'v':
                cout << "Please input x and y value:" << endl;
                cout << "x: ";
                cin >> x;
                cout << "y: ";
                cin >> y;
                terrain[y][x].showTerrianInfo();
                commandCatcher(&cmd);
                continue;
                break;
            case 'f':
                showMap(terrain, 40, 20);
                commandCatcher(&cmd);
                break;
            default:
                cout << "Invaild command, please try again: ";
                cin >> cmd;
                continue;
        }
    }
}
