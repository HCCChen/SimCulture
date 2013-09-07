/*
	操作文化模擬進程
*/

#include "lib/Culture.h"
#include "lib/Terrain.h"

int main(int argc, char* argv[]){
	srand((unsigned)time(NULL));
	Terrain terrain(100, 100, 'c');
	Culture culture[3];

	terrain.generalMap('c');
	terrain.showMap();
	return 0;
}
