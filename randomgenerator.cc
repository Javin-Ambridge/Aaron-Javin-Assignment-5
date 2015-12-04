#include "randomgenerator.h"
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

RandomGenerator::RandomGenerator(){
	srand(time(NULL));
}

int RandomGenerator::getDiceRoll(){
	int tmp;
	tmp = rand() % 6 + 1;
	return tmp;
}

int RandomGenerator::getSLCRoll(){
	int tmp;
	tmp = rand() % 24 + 1;
	return tmp;
}

int RandomGenerator::getNeedlesRoll(){
	int tmp;
	tmp = rand() % 18 + 1;
	return tmp;
}

bool RandomGenerator::wonRollupCup(){
	int win = 25;
	int tmp;
	tmp = rand() % 100 + 1;
	if(tmp == win)
		return true;
	return false;
}
