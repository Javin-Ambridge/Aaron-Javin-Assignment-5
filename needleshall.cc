#include "needleshall.h"
#include <string>
using namespace std;

int NeedlesHall::getMoneyChange(int probability){
	if(probability == 1)
		return -200;
	if(probability == 2 || probability == 3)
		return -100;
	if(probability >= 4 && probability <= 6)
		return -50;
	if(probability >= 7 && probability <= 12)
		return 25;
	if(probability >= 13 && probability <= 15)
		return 50;
	if(probability >= 16 && probability <= 17)
		return 100;
	if(probability == 18)
		return 200;
	return 0;
}