#include "slc.h"
#include <string>
using namespace std;

int SLC::getMove(int probability){
	if(probability >= 1 && probability <= 3)
		return -3;
	if(probability >= 4 && probability <= 7)
		return -2;
	if(probability >= 8 && probability <= 11)
		return -1;
	if(probability >= 12 && probability <= 14)
		return 1;
	if(probability >= 15 && probability <= 18)
		return 2;
	if(probability >= 19 && probability <= 22)
		return 3;
	if(probability == 23)
		return 10; //Dc tims line
	if(probability == 24)
		return 20; //Collect osap
	return 100;
}