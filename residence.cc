#include <string>
#include "residence.h"
using namespace std;

	Residence::Residence(string n, int ind, Player **playerArray, Tile **boardArray){
		name = n;
		purchaseCost = 150;
		buyable = true;
		event = false;
		index = ind;
		tuition = 0;
		improvementCost = 0;
		numImprovements = 0;
		string monopolyBlock = "NA";
		players = playerArray;
		board = boardArray;
	}

	Residence::~Residence(){

	}

	bool Residence::improveAmount(int improves){
		return true;
	}

	string Residence::getName(){
		return name;
	}

	bool Residence::isBuyable(){
		return buyable;
	}

	bool Residence::isEvent(){
		return event;
	}

	int Residence::getTuition(){
		string res1 = "";
		string res2 = "";
		string res3 = "";
		string res4 = "";
		for(int i = 0; i < 8; i++){
			if(players[i] != NULL){
				if(players[i]->ownsBlock(board[5])) //MKV
					res1 = players[i]->getName();
				if(players[i]->ownsBlock(board[15])) //UWP
					res2 = players[i]->getName();
				if(players[i]->ownsBlock(board[25])) //V1
					res3 = players[i]->getName();
				if(players[i]->ownsBlock(board[35])) //REV
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

	string Residence::getMonopolyBlock(){
		return monopolyBlock;
	}

	int Residence::getIndex(){
		return index;
	}

	void Residence::setBuyable(bool buy){
		buyable = buy;
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

	void Residence::setNumImprovements(){
		numImprovements++;
	}