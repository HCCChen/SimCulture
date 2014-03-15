/*
	操作文化模擬進程
*/

#include "lib/Culture.h"
#include "lib/Terrain.h"
#include "lib/Calculate.h"

int main(int argc, char* argv[]){
	srand((unsigned)time(NULL));
	Terrain terrain[20][20];
	int i,j;
	Culture culture[3];

	//Create Map
	for(i = 0; i < 20; i++){
		for(j = 0; j < 20; j++){
			terrain[i][j].generalTerrian('c');
		}
	}

	for(i = 0; i < 20; i++){
		for(j = 0; j < 20; j++){
			cout << terrain[i][j].getTerrianType() << " ";
		}
		cout << endl;
	}

	return 0;
}
