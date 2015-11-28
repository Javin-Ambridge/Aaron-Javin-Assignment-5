#include "player.h"
#include "game.h"
#include <cstdlib>
#include <string>

Player::Player(string name, string piece){
	name = name;
	piece = piece;
	money = 1500;
	rollUpCup = 0;
	properties = NULL;
	numProperties = 0;
	DCTimsLine = 0;
}

Player::~Player(){
	delete [] properties;
}

//GETTERS 
string Player::getName(){
	return name;
}

string Player::getPiece(){
	return piece;
}

int Player::getMoney(){
	return money;
}

int Player::getNetWorth(){
	int netWorth = money;
	for (int i = 0; i < numProperties; i++){
		netWorth += properties[i]->getPurchaseCost();
		netWorth += (properties[i]->getNumImprovements() * properties[i]->getImprovementCost());
	}
	return netWorth;
}

Tile * Player::getPos(){
	return pos;
}

int Player::getDCTimsLine(){
	return DCTimsLine;
}

int Player::getRollUpCup(){
	return rollUpCup;
}

int Player::getLastDieRoll(){
	return lastDieRoll;
}

//PLAYER MOVES
void displayAssets(){
	cout << "Player: " << name << "| Piece: " << piece << endl;
	cout << "Assets:" << endl;
	cout << "Current Money: " << money << endl;
	cout << "Properties owned: " << endl;
	for(int i = 0; i < numProperties; i++){
		cout << properties[i]->getName();
	}
	cout << "Number of Roll Up Cups: " << rollUpCup << endl;
}

void bankrupt(Player * otherPlayer){

}

void Player::addMoney(int addition){
	money += addtion;
}

bool Player::subMoney(int subtraction){
	if (money - subtraction < 0){
		cout << "Insufficient funds!" << endl;
		return false;
	}
	money -= subtraction;
	return true;
}

void updatePos(Tile & t){
	pos = t;
}

void Player::setDCTimsLine(int turns){
	DCTimsLine = turns;
}

void Player::addRollUpCup(){
	rollUpCup = rollUpCup + 1;
}

void Player::removeRollUpCup(){
	rollUpCup = rollUpCup - 1;
}

void Player::setLastDieRoll(int die){
	lastDieRoll = die;
}

bool Player::ownsBlock(Tile * t){
	int tileNum = t->getIndex();
	bool tile1 = false;
	bool tile2 = false;
	bool tile3 = false;
	if (tileNum == 1 || tileNum == 3){
		for (int i = 0; i < numProperties; i++){
			if (properties[i]->getIndex == 1){
				tile1 = true;
			} else if (properties[i]->getIndex == 3){
				tile2 = true;
			}
		}
		return (tile1 && tile2);
	} else if (tileNum == 6 || tileNum == 8 || tileNum == 9){
		for (int i = 0; i < numProperties; i++){
			if (properties[i]->getIndex == 6){
				tile1 = true;
			} else if (properties[i]->getIndex == 8){
				tile2 = true;
			} else if (properties[i]->getIndex == 9){
				tile3 = true;
			}
		}
		return (tile1 && tile2 && tile3);
	} else if (tileNum == 11 || tileNum == 13 || tileNum == 14){
		for (int i = 0; i < numProperties; i++){
			if (properties[i]->getIndex == 11){
				tile1 = true;
			} else if (properties[i]->getIndex == 13){
				tile2 = true;
			} else if (properties[i]->getIndex == 14){
				tile3 = true;
			}
		}
		return (tile1 && tile2 && tile3);
	} else if (tileNum == 16 || tileNum == 18 || tileNum == 19){
		for (int i = 0; i < numProperties; i++){
			if (properties[i]->getIndex == 16){
				tile1 = true;
			} else if (properties[i]->getIndex == 18){
				tile2 = true;
			} else if (properties[i]->getIndex == 19){
				tile3 = true;
			}
		}
		return (tile1 && tile2 && tile3);
	} else if (tileNum == 21 || tileNum == 23 || tileNum == 24){
		for (int i = 0; i < numProperties; i++){
			if (properties[i]->getIndex == 21){
				tile1 = true;
			} else if (properties[i]->getIndex == 23){
				tile2 = true;
			} else if (properties[i]->getIndex == 24){
				tile3 = true;
			}
		}
		return (tile1 && tile2 && tile3);
	} else if (tileNum == 26 || tileNum == 27 || tileNum == 29){
		for (int i = 0; i < numProperties; i++){
			if (properties[i]->getIndex == 26){
				tile1 = true;
			} else if (properties[i]->getIndex == 27){
				tile2 = true;
			} else if (properties[i]->getIndex == 29){
				tile3 = true;
			}
		}
		return (tile1 && tile2 && tile3);
	} else if (tileNum == 31 || tileNum == 32 || tileNum == 34){
		for (int i = 0; i < numProperties; i++){
			if (properties[i]->getIndex == 31){
				tile1 = true;
			} else if (properties[i]->getIndex == 32){
				tile2 = true;
			} else if (properties[i]->getIndex == 34){
				tile3 = true;
			}
		}
		return (tile1 && tile2 && tile3);
	} else if (tileNum == 37 || tileNum == 39){
			if (properties[i]->getIndex == 37){
				tile1 = true;
			} else if (properties[i]->getIndex == 39){
				tile2 = true;
			}
		}
		return (tile1 && tile2);
	} else{
		return false;
	}
}

// Buying improvements
void Player::improve(Tile * t, int numImprovements){
	Player *owner = t->getOwner();
	//Check if Tile is already owned, if current player is the owner, if player owns the block, and if more improvements are allowed
	if (owner && owner->getPiece() == this->piece && ownsBlock(t) && t->getNumImprovements() + numImprovements < 5){
		subMoney(t->getImprovementCost() * numImprovements);
		t->improveAmount(numImprovements);
	} else {
		cout << "You cannot buy improvements for " << t->getName() << endl;
	}
}

// Selling improvements
void Player::unimprove(Tile * t, int numImprovements){
	Player *owner = t->getOwner();
	//Check if Tile is already owned, if current player is the owner, if player owns the block, and if more improvements are allowed
	if (owner && owner->getPiece() == this->piece && ownsBlock(t) && t->getNumImprovements() - numImprovements > 0){
		addMoney(t->getImprovementCost() * numImprovements);
		//	***************************************UNIMPROVE HERE*********************************
	} else {
		cout << "You cannot sell improvements for " << t->getName() << endl;
	}
}

/*
void Player::mortgage(Tile * t){
	Player *owner = t->getOwner();
	//Check if Tile is owned and if current player is the owner
	if (owner && owner->getPiece == this->piece){
		addMoney(t->getPurchaseCost());
		// *********************************************MORTGAGE HERE*********************************************
	} else {
		cout << "You cannot mortgage " << t->getName() << endl;
	}
}

void Player::unmortgage(Tile * t){
	Player *owner = t->getOwner();
	//Check if Tile is owned and if current player is the owner
	if (owner && owner->getPiece == this->piece){
		subMoney(t->getPurchaseCost() * 0.6);
		// *********************************************UNMORTGAGE HERE*********************************************
	} else {
		cout << "You cannot unmortgage " << t->getName() << endl;
	}
}*/

bool Player::hasProperty(Tile & t){
	for (int i = 0; i < numProperties; i++){
		if (properties[i] == t){
			return true;
		}
	}
	return false;
}

// Buy Property
void Player::addProperty(Tile & t){
	if (numProperties == 0){
		properties = new Tile *[40];
	}
	properties[numProperties] = t;
	numProperties++;
}

// Sell Property
void Player::removeProperty(Tile & t){
	for (int i = 0; i < numProperties; i++){
		if (properties[i]->getName() == t->getName()){
			for (int k = i; k + 1 < numProperties; k++){
				properties[k] = properties[k+1];
			}
		}
	}
	numProperties--;
}