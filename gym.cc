#include "gym.h"
#include <string>
using namespace std;

	Gym::Gym(string n, int ind, Player **playerArray, Tile **boardArray, RandomGenerator *gen){
		name = n;
		purchaseCost = 150;
		buyable = true;
		event = false;
		index = ind;
		tuition = 0;
		improvementCost = 0;
		numImprovements = 0;
		string monopolyBlock = "NA";
		for(int i = 0; i < 8; i++)
			players[i] = playerArray[i];
		for(int i = 0; i < 40; i++)
			board[i] = boardArray[i];
		generator = gen;
	}

	Gym::~Gym(){

	}

	bool Gym::improveAmount(int improves){
		return true;
	}

	string Gym::getName(){
		return name;
	}

	bool Gym::isBuyable(){
		return buyable;
	}

	bool Gym::isEvent(){
		return event;
	}

	int Gym::getTuition(){
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

	int Gym::getPurchaseCost(){
		return purchaseCost;
	}

	int Gym::getImprovementCost(){
		return improvementCost;
	}

	string Gym::getMonopolyBlock(){
		return monopolyBlock;
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

	void Gym::setNumImprovements(){
		numImprovements++;
	}