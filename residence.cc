#include <string>
#include <iostream>
#include "residence.h"
using namespace std;
#define MAX_PROPERTIES 40
#define MAX_PLAYERS 8

//Residence Tile constructor
Residence::Residence(string n, int ind){
	name = n;
	purchaseCost = 150;
	buyable = true;
	mortgaged = false;
	index = ind;
	tuition = 0;
	improvementCost = 0;
	numImprovements = 0;
	string monopolyBlock = "NA";
	additionalUnmortgagedFee = false;
}

//Residence Tile Destructor
Residence::~Residence(){

}

//Return the name of Residence Tile
string Residence::getName(){
	return name;
}

//Return if Residence Tile is buyable
bool Residence::isBuyable(){
	return buyable;
}

//Residence is a smart tile and needs to know the number of players
//Adds player to Player array
void Residence::addPlayer(Player *p){
	for(int i = 0; i < MAX_PLAYERS; i++){
		if(players[i] == NULL){
			players[i] = p;
			return;
		}
	}
}

//Residence is a smart tile and needs to know the board
//Populates board with boardArray
void Residence::addBoard(Tile **boardArray){
	for(int i = 0; i < MAX_PROPERTIES; i++){
		board[i] = boardArray[i];
	}
}

//Return the tutition payment for Residence Tile
int Residence::getTuition(){
	string res1 = "";
	string res2 = "";
	string res3 = "";
	string res4 = "";
	for(int i = 0; i < 8; i++){
		if(players[i] != NULL){
			if(players[i]->hasProperty(*board[5])) //MKV
				res1 = players[i]->getName();
			if(players[i]->hasProperty(*board[15])) //UWP
				res2 = players[i]->getName();
			if(players[i]->hasProperty(*board[25])) //V1
				res3 = players[i]->getName();
			if(players[i]->hasProperty(*board[35])) //REV
				res4 = players[i]->getName();
		}
	}
	int count = 1;
	if(index == 5){
		if(res2 == res1)
			count++;
		if(res3 == res1)
			count++;
		if(res4 == res1)
			count++;
	}else if(index == 15){
		if(res2 == res1)
			count++;
		if(res2 == res3)
			count++;
		if(res2 == res4)
			count++;
	}else if(index == 25){
		if(res3 == res1)
			count++;
		if(res3 == res2)
			count++;
		if(res3 == res4)
			count++;
	}else{
		if(res4 == res1)
			count++;
		if(res4 == res2)
			count++;
		if(res4 == res3)
			count++;
	}
	if(count == 1){
		return 25;
	}else if(count == 2){
		return 50;
	}else if(count == 3){
		return 100;
	}else{
		return 200;
	}
}

//Return the purchase cost for Residence Tile
int Residence::getPurchaseCost(){
	return purchaseCost;
}

//virtual function needed for Property Tiles
int Residence::getImprovementCost(){
	return improvementCost;
}

//Returns the index of the Residence Tile
int Residence::getIndex(){
	return index;
}

//Sets buyable of Residence Tile to buy
void Residence::setBuyable(bool buy){
	buyable = buy;
}

//Set index of Residence Tile to ind
void Residence::setIndex(int ind){
	index = ind;
}

//virtual function needed for Property Tiles
int Residence::getMove(int probability){
	return 1;
}	

//virtual function needed for Property Tiles
int Residence::getMoneyChange(int probability){
	return 1;
}

//virtual function needed for Property Tiles
int Residence::getNumImprovements(){
	return numImprovements;
}

//virtual function needed for Property Tiles
void Residence::setNumImprovements(int improves){
	numImprovements++;
}

//virtual function needed for Property Tiles
bool Residence::getMortgaged(){
	return mortgaged;
}

//virtual function needed for Property Tiles
void Residence::setMortgaged(bool mortgaged){
	mortgaged = mortgaged;
}

//virtual function needed for Property Tiles
void Residence::setAdditionalUnmortgagedFee(bool fee){
	additionalUnmortgagedFee = fee;
}

//virtual function needed for Property Tiles
bool Residence::getAdditionalUnmortgagedFee(){
	return additionalUnmortgagedFee;
}