/*
	文明模擬基本操作
	提供顯示；初始化；操作文明互動；時間流逝發展
*/

#include "Culture.h"

Culture::Culture(){
	weather = getRandom(60,100);
	terrain = getRandom(60,100);
	resources = getRandom(1,10);
	people = getRandom(5,10);
	economic = getRandom(1,10);
	science = getRandom(1,10);
	political = getRandom(60,80);
	religion = getRandom(0,100);
	culture = getRandom(1,10);
	deltaWeather = 0;
	deltaTerrain = 0;
	deltaResources = 0;
	deltaPeople = 0;
	deltaEconomic = 0;
	deltaScience = 0;
	deltaPolitical = 0;
	deltaReligion = 0;
	deltaCulture = 0;
	surviveTime = 0;
}

/*
	顯示分數
*/
void Culture::showResult(){
	cout << "氣候分數: " << weather << "/100" << endl;
	cout << "地形分數: " << terrain << "/100" << endl;
	cout << "政治分數: " << political << "/100" << endl;
	cout << "宗教分數: " << religion << "/100" << endl;
	cout << "人口分數: " << people << "千人" << endl;
	cout << "資源分數: " << resources << endl;
	cout << "經濟分數: " << economic << endl;
	cout << "科技分數: " << science << endl;
	cout << "文化分數: " << culture << endl;
	cout << "總體分數: " << "--" << endl;
	cout << "生存時間: " << surviveTime << "時" << endl;
}

void Culture::simARound(){
	weather += deltaWeather;
	terrain += deltaTerrain;
	resources += deltaResources;
	people += deltaPeople;
	economic += deltaEconomic;
	science += deltaScience;
	political += deltaPolitical;
	culture += deltaCulture;
	surviveTime += 1;

}

int Culture::getRandom(int begin, int end){
	return rand()%(end-begin)+begin;
}
