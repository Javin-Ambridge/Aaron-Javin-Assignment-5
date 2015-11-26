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