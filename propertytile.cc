#include "propertytile.h"
#include <string>
#include <iostream>
using namespace std;

//Property Tiile constructor
PropertyTile::PropertyTile(string n, int purch, int ind, int *improves, string monop, int improveC){
	name = n;
	purchaseCost = purch;
	buyable = true;
	mortgaged = false;
	index = ind;
	tuition = 0;
	improvementCost = improveC;
	numImprovements = 0;
	string monopolyBlock = monop;
	additionalUnmortgagedFee = false;
	if(improves != NULL){			
		for(int i = 0; i < 6; i++)
			improveArray[i] = improves[i];
	}
}

//Property Tile Destructor
PropertyTile::~PropertyTile(){

}

//Set index of Property Tile to ind
void PropertyTile::setIndex(int ind){
	index = ind;
}

//Return the name of Property Tile
string PropertyTile::getName(){
	return name;
}

//Return if Property Tile is buyable
bool PropertyTile::isBuyable(){
	return buyable;
}

//Return the tutition payment for Property Tile
int PropertyTile::getTuition(){
	return improveArray[numImprovements];
}

//Return the purchase cost for Property Tile
int PropertyTile::getPurchaseCost(){
	return purchaseCost;
}

//Return the improvement cost for Property Tile
int PropertyTile::getImprovementCost(){
	return improvementCost;
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

void PropertyTile::setNumImprovements(int improves){
	if(improves > 0)
		numImprovements = numImprovements + improves;
	else{
		improves = improves * -1;
		numImprovements = numImprovements - improves;
	}
}

bool PropertyTile::getMortgaged(){
	return mortgaged;
}

void PropertyTile::setMortgaged(bool mortgage){
	mortgaged = mortgage;
}

void PropertyTile::setAdditionalUnmortgagedFee(bool fee){
	additionalUnmortgagedFee = fee;
}

bool PropertyTile::getAdditionalUnmortgagedFee(){
	return additionalUnmortgagedFee;
}