#include "gym.h"
#include <string>
#include <iostream>
using namespace std;

//Gym constructor
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

//Gym Destructor
Gym::~Gym(){

}

string Gym::getName(){
	return name;
}

bool Gym::isBuyable(){
	return buyable;
}

void Gym::addPlayer(Player *p){
	for(int i = 0; i < 8; i++){
		if(players[i] == NULL){
			players[i] = p;
			return;
		}
	}
}

void Gym::addBoard(Tile **boardArray){
	for(int i = 0; i < 40; i++){
		board[i] = boardArray[i];
	}
}

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

int Gym::getPurchaseCost(){
	return purchaseCost;
}

int Gym::getImprovementCost(){
	return improvementCost;
}

int Gym::getIndex(){
	return index;
}

void Gym::setBuyable(bool buy){
	buyable = buy;
}

int Gym::getMove(int probability){
	return 1;
}	

void Gym::setIndex(int ind){
	index = ind;
}

int Gym::getMoneyChange(int probability){
	return 1;
}

int Gym::getNumImprovements(){
	return numImprovements;
}

void Gym::setNumImprovements(int improves){
	numImprovements++;
}

bool Gym::getMortgaged(){
	return mortgaged;
}

void Gym::setMortgaged(bool mortgaged){
	mortgaged = mortgaged;
}

void Gym::setAdditionalUnmortgagedFee(bool fee){
	additionalUnmortgagedFee = fee;
}

bool Gym::getAdditionalUnmortgagedFee(){
	return additionalUnmortgagedFee;
}