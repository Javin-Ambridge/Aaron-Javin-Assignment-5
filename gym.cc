#include "gym.h"
#include <string>
#include <iostream>
using namespace std;

//Gym Tile constructor
Gym::Gym(string n, int ind, RandomGenerator *gen){
	name = n;
	purchaseCost = 150;
	buyable = true;
	mortgaged = false;
	index = ind;
	tuition = 0;
	improvementCost = 0;
	numImprovements = 0;
	string monopolyBlock = "NA";
	generator = gen;
	additionalUnmortgagedFee = false;
}

//Gym Tile Destructor
Gym::~Gym(){

}

//Return the name of Gym Tile
string Gym::getName(){
	return name;
}

//Return if Gym Tile is buyable
bool Gym::isBuyable(){
	return buyable;
}

//Gym is a smart tile and needs to know the number of players
//Adds player to Player array
void Gym::addPlayer(Player *p){
	for(int i = 0; i < 8; i++){
		if(players[i] == NULL){
			players[i] = p;
			return;
		}
	}
}

//Gym is a smart tile and needs to know the board
//Populates board with boardArray
void Gym::addBoard(Tile **boardArray){
	for(int i = 0; i < 40; i++){
		board[i] = boardArray[i];
	}
}

//Return the tutition payment for Gym Tile
int Gym::getTuition(){
	string playerName1 = "";
	string playerName2 = "";
	for(int i = 0; i < 8; i++){
		if(playerName1 != "" && playerName2 != "")
			break;
		if(players[i] != NULL){
			if(players[i]->hasProperty(*board[12]))
				playerName1 = players[i]->getName();
			if(players[i]->hasProperty(*board[28]))
				playerName2 = players[i]->getName();
		}
	}
	if(playerName2 == playerName1){
		int roll = generator->getDiceRoll() + generator->getDiceRoll();
		return roll * 10;
	}else{
		int roll = generator->getDiceRoll() + generator->getDiceRoll();
		return roll * 4;
	}
}

//Return the purchase cost for Gym Tile
int Gym::getPurchaseCost(){
	return purchaseCost;
}

//Return the improvement cost for Gym Tile
int Gym::getImprovementCost(){
	return improvementCost;
}

//Returns the index of the Gym Tile
int Gym::getIndex(){
	return index;
}

//Sets buyable of Gym Tile to buy
void Gym::setBuyable(bool buy){
	buyable = buy;
}

//virtual function needed for Property Tiles
int Gym::getMove(int probability){
	return 1;
}	

//Set index of Gym Tile to ind
void Gym::setIndex(int ind){
	index = ind;
}

//virtual function needed for Property Tiles
int Gym::getMoneyChange(int probability){
	return 1;
}

//virtual function needed for Property Tiles
int Gym::getNumImprovements(){
	return numImprovements;
}

//virtual function needed for Property Tiles
void Gym::setNumImprovements(int improves){
	numImprovements++;
}

//virtual function needed for Property Tiles
bool Gym::getMortgaged(){
	return mortgaged;
}

//virtual function needed for Property Tiles
void Gym::setMortgaged(bool mortgaged){
	mortgaged = mortgaged;
}

//virtual function needed for Property Tiles
void Gym::setAdditionalUnmortgagedFee(bool fee){
	additionalUnmortgagedFee = fee;
}

//virtual function needed for Property Tiles
bool Gym::getAdditionalUnmortgagedFee(){
	return additionalUnmortgagedFee;
}