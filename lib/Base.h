#ifndef BASE_FUNCTION
#define BASE_FUNCTION
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <unistd.h>
#include <fstream>
#include <string>
#include <fstream>

using namespace std;

//Global Setting, initial data is define at "setting.conf"
const static string CONFIG_FILE_PATH = "resources/setting.conf";
static string LANGUAGE_PACKAGE_PATH;
static string LANGUAGE;

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
//Load string information from file
bool loadLanguagePack();
//Write log into file
void log(string logContext);
#endif /* BASE_FUNCTION */
