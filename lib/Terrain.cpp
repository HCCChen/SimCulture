#include "Terrain.h"

Terrain::Terrain(int width, int height, char type){
	int loopCounter1, loopCounter2;
	mapWidth = width;
	mapHeight = height;
	mapSpace = new char*[height];
	mapElevation = new int*[height];
	for(loopCounter1 = 0; loopCounter1 < height; loopCounter1++){
		mapSpace[loopCounter1] = new char[width];
		mapElevation[loopCounter1] = new int[height];
	}
		
	for(loopCounter1 = 0; loopCounter1 < height; loopCounter1++){
		for(loopCounter2 = 0; loopCounter2 < width; loopCounter2++){
			mapSpace[loopCounter1][loopCounter2] = '.';
			mapElevation[loopCounter1][loopCounter2] = 0;
		}
	}
}

bool Terrain::showMap(){
	int loopCounter1, loopCounter2;
	for(loopCounter1 = 0; loopCounter1 < mapHeight; loopCounter1++){
		for(loopCounter2 = 0; loopCounter2 < mapWidth; loopCounter2++){
			cout <<mapSpace[loopCounter1][loopCounter2];
		}
		cout << endl;
	}

	return true;
}

bool Terrain::generalMap(char type){
	int loopCounter1, loopCounter2;
	for(loopCounter1 = 0; loopCounter1 < mapHeight; loopCounter1++){
		for(loopCounter2 = 0; loopCounter2 < mapWidth; loopCounter2++){
			mapSpace[loopCounter1][loopCounter2] = type;
		}
		cout << endl;
	}
	return true;
}
