#include <string>
#include <iostream>
#include "game.h"
using namespace std;

Game::Game(View *v){
	view = v;
	generator = new RandomGenerator();
	board[0] = new CollectOSAP("Collect OSAP");
	board[1] = new PropertyTile("AL");
	board[2] = new SLC("SLC");
	board[3] = new PropertyTile("ML");
	board[4] = new Tuition("Tuition");
	board[5] = new PropertyTile("MKV");
	board[6] = new PropertyTile("ECH");
	board[7] = new NeedlesHall("Needles Hall");
	board[8] = new PropertyTile("PAS");
	board[9] = new PropertyTile("HH");
	board[10] = new DCTimsLine("DC Tims Line");
	board[11] = new PropertyTile("RCH");
	board[12] = new Gym("PAC");
	board[13] = new PropertyTile("DWE");
	board[14] = new PropertyTile("CPH");
	board[15] = new PropertyTile("UWP");
	board[16] = new PropertyTile("LHI");
	board[17] = new SLC("SLC");
	board[18] = new PropertyTile("BMH");
	board[19] = new PropertyTile("OPT");
	board[20] = new GooseNesting("Goose Nesting");
	board[21] = new PropertyTile("EV1");
	board[22] = new NeedlesHall("Needles Hall");
	board[23] = new PropertyTile("EV2");
	board[24] = new PropertyTile("EV3");
	board[25] = new PropertyTile("V1");
	board[26] = new PropertyTile("PHYS");
	board[27] = new PropertyTile("B1");
	board[28] = new Gym("CIF");
	board[29] = new PropertyTile("B2");
	board[30] = new GoToTims("Go To Tims");
	board[31] = new PropertyTile("EIT");
	board[32] = new PropertyTile("ESC");
	board[33] = new SLC("SLC");
	board[34] = new PropertyTile("C2");
	board[35] = new PropertyTile("REV");
	board[36] = new NeedlesHall("Needles Hall");
	board[37] = new PropertyTile("MC");
	board[38] = new CoopFee("Coop Fee");
	board[39] = new PropertyTile("DC");
	for(int i = 0; i < 8; i++)
		players[i] = NULL;
}

void Game::auction(Tile *t){

}

bool Game::isActive(){
	return active;
}

void Game::addPlayer(string name, string piece){
	for(int i = 0; i < 8; i++){
		if(players[i] == NULL){
			players[i] = new Player(name, piece);
			return;
		}
	}
}

int Game::playerWhoOwns(Tile *t){
	for(int i = 0; i < 8; i++){
		if(players[i] != NULL){
			if(players[i]->hasProperty(*t))
				return i;
		}
	}
	return -1;
}



void Game::doMove(int playerIndex){
	Player *currentPlayer = players[playerIndex];
	bool hasRolled = false;
	while(true){
		string command;
		cout << "Please enter a valid command:" << endl;
		cin >> command;
		if(command == "roll"){
			if(hasRolled){
				cout << "You have already rolled, you cannot use this command this turn." << endl;
				continue;
			}
			int rollNum = generator->getDiceRoll() + generator->getDiceRoll();
			//Need to check for double roll. and triple roll.
			int currentPosition = currentPlayer->getPos()->getIndex();
			currentPosition = currentPosition + rollNum;
			if(currentPosition > 39){
				cout << "Congragulations you have passed collect OSAP, you gain $200!" << endl;
				currentPlayer->addMoney(200);
				cout << "Your new balance is: " << currentPlayer->getMoney() << endl;
				currentPosition = currentPosition - 40;
			}
			Tile *currentTile = board[currentPosition];
			if(currentTile->getName() == "SLC"){ //Still need to check for rollup the rim cups
				int changeOfPos = currentTile->getMove(generator->getSLCRoll());
				if(changeOfPos == 23){
					cout << "SLC probabilities have moved you to the DC Tims Line... Unfortunate.." << endl;
					// DC Tims Line
				}
				else if(changeOfPos == 24){
					cout << "SLC probabilities have moved you to colled OSAP! Thats lucky...." << endl;
					currentPosition = 0;
					cout << "Congragulations you have landed on Collect OSAP, you gain $200!" << endl;
					currentPlayer->addMoney(200);
					cout << "Your new balance is: " << currentPlayer->getMoney() << endl;
				}else{
					cout << "SLC probabilities have move you this many spaces: " << changeOfPos << endl;
					currentPosition = currentPosition + changeOfPos;
				}
				if(currentPosition > 39){
					cout << "Congragulations you have passed collect OSAP, you gain $200!" << endl;
					currentPlayer->addMoney(200);
					cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
					currentPosition = currentPosition - 40;
				}
				currentTile = board[currentPosition];
			}
			if(currentTile->getName() == "Go To Tims"){

			}
			if(currentTile->getName() == "Coop Fee"){
				
			}
			if(currentTile->getName() == "Collect OSAP"){
				hasRolled = true;
				continue;
			}
			if(currentTile->getName() == "Goose Nesting"){
				hasRolled = true;
				continue;
			}
			if(currentTile->getName() == "DC Tims Line"){
				//Need to check if I have been sent there or not.
			}
			if(currentTile->getName() == "Needles Hall"){ //Still need to check for roll up the rims.
				int moneyChange = currentTile->getMoneyChange(generator->getNeedlesRoll());
				if(moneyChange > 0){
					cout << "Congragulations you just won $" << moneyChange << " from Needles Hall!" << endl;
					currentPlayer->addMoney(moneyChange);
					cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
				}else{
					moneyChange = moneyChange * -1;
					cout << "UHOH! You unfortunately lost $" << moneyChange << " at Needles Hall.." << endl;
					currentPlayer->subMoney(moneyChange);
					cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
				}
				hasRolled = true;
				continue;
			}
			if(currentTile->isBuyable()){
				cout << "Looks like this property: " << currentTile->getName() << " is purchasable!" << endl;
				cout << "Would you like to purchase it? The cost of the property is: " << currentTile->getPurchaseCost() << ". Yes/No" << endl;
				string input;
				cin >> input;
				while(input != "Yes" || input != "No"){
					cout << "Invalid input. Please enter Yes or No." << endl;
					cin >> input;
				}
				if(input == "Yes"){
					//Need to check for invalid amount of money here.
					int purchaseCost = currentTile->getPurchaseCost();
					currentPlayer->addProperty(*currentTile);
					currentPlayer->subMoney(purchaseCost);
					currentTile->setBuyable(false);
					cout << "Congragulations you have just purchased " << currentTile->getName() << endl;
					cout << "Your current balance is now " << currentPlayer->getMoney() << endl;
					hasRolled = true;
					continue; //Need to update the view before this.
				}else{
					auction(currentTile); //Need to update the view after this.
				}
			}else{
				//Need to check that the person has enough money to pay the other player.
				cout << "UHOH! Someone owns this property, you need to pay them!" << endl;
				int playerOwner = playerWhoOwns(currentTile);
				cout << "You are paying " << players[playerOwner]->getName() << " this much money: $" << currentTile->getTuition() << endl;
				int payableMoney = currentTile->getTuition();
				players[playerOwner]->addMoney(payableMoney);
				currentPlayer->subMoney(payableMoney);
				cout << "Your current balance is now: " << currentPlayer->getMoney() << endl;
				hasRolled = true;
				continue; //Need to update the view before this.
			}
		}
		if(command == "next"){

		}
		if(command == "trade"){

		}
		if(command == "improve"){

		}
		if(command == "mortgage"){

		}
		if(command == "unmortgage"){

		}
		if(command == "bankrupt"){

		}
		if(command == "assets"){

		}
		if(command == "save"){

		}
	}
}

void Game::setNumberOfPlayers(int num){
	numberOfPlayers = num;
}

int Game::getNumberOfPlayers(){
	return numberOfPlayers;
}

bool Game::isPieceUsed(string piece){
	for(int i = 0; i < 8; i++){
		if(players[i] != NULL){
			if(players[i]->getPiece() == piece)
				return true;
		}
	}
	return false;
}

Tile *Game::getPosition(int playerIndex){
	return players[playerIndex]->getPos();
}

Game::~Game(){
	for(int i = 0; i < 40; i++)
		delete board[i];
	for(int i = 0; i < 8; i++){
		if(players[i] != NULL)
			delete players[i];
	}
	delete generator;
}
