#include "Calculate.h"

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

