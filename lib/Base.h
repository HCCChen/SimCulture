#ifndef BASE_FUNCTION
#define BASE_FUNCTION
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <string>
#include <fstream>

//Define command cross OS
#if defined(_WIN32) || defined(_WIN64)  //For Windows
#include <windows.h>
#define sleep(n) Sleep(1000 * (n))
#define clearScreen() system("cls")
#else  //For unix
#include <unistd.h>
#define clearScreen() system("clear")
#endif

#include "Language.h"

using namespace std;


//Context information

//Index of cultrue parameter.
enum idxVariable{
    IDX_CULTURE_WEATHER,
    IDX_CULTURE_TERRAIN,
    IDX_CULTURE_RESOURCES,
    IDX_CULTURE_PEOPLE,
    IDX_CULTURE_ECONOMIC,
    IDX_CULTURE_SCIENCE,
    IDX_CULTURE_POLITICAL,
    IDX_CULTURE_RELIGION,
    IDX_CULTURE_CULTURE,
    IDX_CULTURE_MAX_COUNT
};

//Color code for prinf text
//Define command cross OS
#if defined(_WIN32) || defined(_WIN64)  //For Windows
const string END_COLOR = "";
const string LIGHT_BLOCK = "";
const string LIGHT_RED = "";
const string LIGHT_GREEN = "";
const string LIGHT_YELLOW = "";
const string LIGHT_BLUE = "";
const string LIGHT_PURPLE = "";
const string LIGHT_CYAN = "";
const string LIGHT_WHITE = "";

const string NORMAL_BLOCK = "";
const string NORMAL_RED = "";
const string NORMAL_GREEN = "";
const string NORMAL_YELLOW = "";
const string NORMAL_BLUE = "";
const string NORMAL_PURPLE = "";
const string NORMAL_CYAN = "";
const string NORMAL_WHITE = "";

#else  //For unix
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
//Change culture parameter idx to string
string cultureIdxToString(int idx);
//Load basic config file
bool loadConfigFile();
//Show all config information
void showConfig();
//Write log into file
void log(string logContext);
#endif /* BASE_FUNCTION */
