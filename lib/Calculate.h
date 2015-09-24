#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <fstream>
#include <string>

using namespace std;

#ifndef COLOR_TAG
#define COLOR_TAG
const string END_COLOR = "\E[0;0;0m";
const string LIGHT_BLOCK = "\E[1;30;40m";
const string LIGHT_RED = "\E[1;31;40m";
const string LIGHT_GREEN = "\E[1;32;40m";
const string LIGHT_YELLOW = "\E[1;33;40m";
const string LIGHT_BLUE = "\E[1;34;40m";
const string LIGHT_PURPLE = "\E[1;35;40m";
const string LIGHT_CYAN = "\E[1;36;40m";
const string LIGHT_WHITE = "\E[1;37;40m";

const string NORMAL_BLOCK = "\E[0;30;40m";
const string NORMAL_RED = "\E[0;31;40m";
const string NORMAL_GREEN = "\E[0;32;40m";
const string NORMAL_YELLOW = "\E[0;33;40m";
const string NORMAL_BLUE = "\E[0;34;40m";
const string NORMAL_PURPLE = "\E[0;35;40m";
const string NORMAL_CYAN = "\E[0;36;40m";
const string NORMAL_WHITE = "\E[0;37;40m";
#endif

//Create random number(integer) in given range, include max/min
int randomPositiveInt(int min, int max);
//Give the happen/un-happen result base on given probability
bool randomBoolean(int numerator, int denominator);
//Write log into file
void log(string logContext);
