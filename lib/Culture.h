#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

typedef struct coordinate {
    int x;
    int y;
} Coordinate;

class Culture{
public:
	Culture();				//初始化
	void	simARound();			//進行一個回合，計算基本參數之變化
	void	showResult();			//輸出結果
	void	saveResult(string fileName);	//將結果存入檔案
	void	loadResult(string fileName);	//載入該次結果
    bool    addTerritory(int x, int y);
private:
	int	getRandom(int begin, int end);	//取得範圍內亂數
    vector<Coordinate> territory;
    int	surviveTime;	//生存時間：單位 hr
    int maxOfScore;
	double	weather;	//氣候分數
	double	terrain;	//地形分數
	double	resources;	//資源分數
	double	people;		//人口分數
	double	economic;	//經濟分數
	double	science;	//科技分數
	double	political;	//政治分數
	double  religion;	//宗教分數
	double	culture;	//文化分數
	double	deltaWeather;	//氣候變化量
	double	deltaTerrain;	//地形變化量
	double	deltaResources;	//資源變化量
	double	deltaPeople;	//人口變化量
	double	deltaEconomic;	//經濟變化量
	double	deltaScience;	//科技變化量
	double	deltaPolitical;	//政治變化量
	double  deltaReligion;	//宗教變化量
	double	deltaCulture;	//文化變化量
};
