#include "propertytile.h"
#include <string>
#include <iostream>
using namespace std;

	PropertyTile::PropertyTile(string n, int purch, int ind, int *improves, string monop, int improveC){
		name = n;
		purchaseCost = purch;
		buyable = true;
		event = false;
		index = ind;
		tuition = 0;
		improvementCost = improveC;
		improveArray = improves;
		numImprovements = 0;
		string monopolyBlock = monop;
	}

	PropertyTile::~PropertyTile(){

	}

	bool PropertyTile::improveAmount(int improves){
		return true;
	}

	string PropertyTile::getName(){
		return name;
	}

	bool PropertyTile::isBuyable(){
		return buyable;
	}

	bool PropertyTile::isEvent(){
		return event;
	}

	int PropertyTile::getTuition(){
		cout << "The tuition is: " << improveArray[numImprovements] << endl;
		return improveArray[numImprovements];
	}

	int PropertyTile::getPurchaseCost(){
		return purchaseCost;
	}

	int PropertyTile::getImprovementCost(){
		return improvementCost;
	}

	string PropertyTile::getMonopolyBlock(){
		return monopolyBlock;
	}

	int PropertyTile::getIndex(){
		return index;
	}

	void PropertyTile::setBuyable(bool buy){
		buyable = buy;
	}

	int PropertyTile::getMove(int probability){
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

	int PropertyTile::getMoneyChange(int probability){
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

	int PropertyTile::getNumImprovements(){
		return numImprovements;
	}

	void PropertyTile::setNumImprovements(){
		numImprovements++;
	}