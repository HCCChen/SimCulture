/*
	操作文化模擬進程
*/

#include "lib/Culture.h"

int main(int argc, char* argv[]){
	srand((unsigned)time(NULL));
	Culture culture[3];
	culture[0].showResult();
	culture[1].showResult();
	culture[2].showResult();
	return 0;
}
