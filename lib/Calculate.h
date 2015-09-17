#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

//Create random number(integer) in given range, include max/min
int randomPositiveInt(int min, int max);
//Give the happen/un-happen result base on given probability
bool randomBoolean(int numerator, int denominator);
