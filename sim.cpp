#include <unistd.h>
#include "lib/Culture.h"
#include "lib/Terrain.h"
#include "lib/Calculate.h"

int randomPositiveInt(int min, int max);
bool randomBoolean(int numerator, int denominator);
int commandHandler(char cmd);
bool commandCatcher(char* cmd);
void showMap(Terrain **map, int weight, int hight);
Terrain** constructMap(int weight, int hight);

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

int randomPositiveInt(int min, int max) {
    int randNum;
    if (min < 0 || max < 0 || min >= max) {
        return -1;
    }
    srand(time(NULL));
    randNum = min + (rand() % (max - min + 1));
    return randNum;
}

bool randomBoolean(int numerator, int denominator) {
    int randNum, randBuf, i;
    int *selectedList;
    if (numerator < 1 || denominator < 1) {
        return false;
    }
    srand(time(NULL));
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

Terrain** constructMap(int weight, int hight) {
    Terrain **terrain;
    int i, j, seedX, seedY, groupCounter;
    //Initialize basic Map
    terrain = new Terrain*[hight];
    for(i = 0; i < hight; i++) {
        terrain[i] = new Terrain[weight];
        for(j = 0; j < weight; j++) {
            terrain[i][j].generalTerrian('.');
        }
    }
    //Generate Hill
    seedX = randomPositiveInt(0, (weight-1));
    seedY = randomPositiveInt(0, (hight-1));
    terrain[seedY][seedX].generalTerrian('M');
    groupCounter = 0;
    while(true) {
        if (randomBoolean(10 - groupCounter, 10) &&
                (seedX + groupCounter) < weight &&
                (seedY + groupCounter) < hight) {
            terrain[seedY + groupCounter][seedX + groupCounter].generalTerrian('M');
            terrain[seedY + groupCounter][seedX + groupCounter + 1].generalTerrian('M');
            groupCounter++;
        } else {
            break;
        }
    }
    return terrain;
}

void showMap(Terrain **map, int weight, int hight) {
    int i, j, ret;
    ret = system("clear");
    for(i = 0; i < hight; i++){
        for(j = 0; j < weight; j++){
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
