#include "propertytile.h"
#include <string>
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
		string playerName1 = "";
		string playerName2 = "";
		for(int i = 0; i < 8; i++){
			if(playerName1 != "" && playerName2 != "")
				break;
			if(players[i] != NULL){
				if(players[i]->ownsBlock(board[12]))
					playerName1 = players[i]->getName();
				if(players[i]->ownsBlock(board[28]))
					playerName2 = players[i]->getName();
			}
		}
		if(playerName2 == playerName1){
			int roll = generator->getDiceRoll() + generator->getDiceRoll();
			return roll * 2;
		}else{
			int roll = generator->getDiceRoll() + generator->getDiceRoll();
			return roll * 10;
		}
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
		return 1;
	}	

	int PropertyTile::getMoneyChange(int probability){
		return 1;
	}

	int PropertyTile::getNumImprovements(){
		return numImprovements;
	}

	int PropertyTile::setNumImprovements(){
		numImprovements++;
	}