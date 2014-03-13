#include "Calculate.h"

//Create random number(integer) in given range
int randomCreater(int from, int end){
	return (from - end)*(double)rand()/RAND_MAX + end;
}
//Give the happen/un-happen result base on given probability
bool isHappen(double probability){
	int proFlag = (int)(probability*100);
	int happenFlag = randomCreater(1, 10000);
	if(happenFlag <= proFlag){return true;}
	else{return false;}
}
