#include <string>
#include <iostream>
#include "residence.h"
using namespace std;

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

Residence::~Residence(){

}

string Residence::getName(){
	return name;
}

bool Residence::isBuyable(){
	return buyable;
}

void Residence::addPlayer(Player *p){
	for(int i = 0; i < 8; i++){
		if(players[i] == NULL){
			players[i] = p;
			return;
		}
	}
}

void Residence::addBoard(Tile **boardArray){
	for(int i = 0; i < 40; i++){
		board[i] = boardArray[i];
	}
}

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

int Residence::getPurchaseCost(){
	return purchaseCost;
}

int Residence::getImprovementCost(){
	return improvementCost;
}

int Residence::getIndex(){
	return index;
}

void Residence::setBuyable(bool buy){
	buyable = buy;
}

void Residence::setIndex(int ind){
	index = ind;
}

int Residence::getMove(int probability){
	return 1;
}	

int Residence::getMoneyChange(int probability){
	return 1;
}

int Residence::getNumImprovements(){
	return numImprovements;
}

void Residence::setNumImprovements(int improves){
	numImprovements++;
}

bool Residence::getMortgaged(){
	return mortgaged;
}

void Residence::setMortgaged(bool mortgaged){
	mortgaged = mortgaged;
}

void Residence::setAdditionalUnmortgagedFee(bool fee){
	additionalUnmortgagedFee = fee;
}

bool Residence::getAdditionalUnmortgagedFee(){
	return additionalUnmortgagedFee;
}