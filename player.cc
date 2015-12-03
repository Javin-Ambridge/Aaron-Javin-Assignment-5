#include "player.h"
#include "game.h"
#include <cstdlib>
#include <string>

using namespace std;

Player::Player(string nam, string piec){
	name = nam;
	piece = piec;
	money = 1500;
	rollUpCup = 0;
	pos = NULL;
	numProperties = 0;
	isBankrupt = false;
}

Player::~Player(){
	//delete [] properties;
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

bool Player::getBankrupt(){
	return isBankrupt;
}

//PLAYER MOVES
void Player::displayAssets(){
	cout << "Player: " << name << " | Piece: " << piece << endl;
	cout << "Assets:" << endl;
	cout << "Current Money: " << money << endl;
	cout << "Properties owned: " << endl;
	if(numProperties == 0)
		cout << "No Properties owned." << endl;
	for(int i = 0; i < numProperties; i++){
		cout << properties[i]->getName() << endl;
	}
	cout << "Number of Roll Up Cups: " <<rollUpCup << endl;
}

void Player::bankrupt(Player * otherPlayer){
	//Transfer whatevery funds left
	otherPlayer->addMoney(money);
	for (int i = 0; i < numProperties; i++){
		otherPlayer->addProperty(*(properties[i]));
	}
	//If the current player owns a rollUpCup and the otherPlayer doesn't, give the otherPlayer the rollUpCup
	if (otherPlayer->getRollUpCup() < 1 && rollUpCup == 1){
		otherPlayer->addRollUpCup();
	}
	money=0;
	numProperties=0;
	rollUpCup=0;
}

void Player::trade(Player * otherPlayer){
}

void Player::addMoney(int addition){
	money += addition;
}

bool Player::subMoney(int subtraction){
	if (money - subtraction < 0){
		cout << "Insufficient funds!" << endl;
		return false;
	}
	money -= subtraction;
	return true;
}

void Player::updatePos(Tile & t){
	pos = &t;
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

void Player::setBankrupt(bool b){
	isBankrupt = b;
}

void Player::setMoney(int amount){
	money = amount;
}

bool Player::ownsBlock(Tile * t){
	int tileNum = t->getIndex();
	bool tile1 = false;
	bool tile2 = false;
	bool tile3 = false;
	if (tileNum == 1 || tileNum == 3){
		for (int i = 0; i < numProperties; i++){
			if (properties[i]->getIndex() == 1){
				tile1 = true;
			} else if (properties[i]->getIndex() == 3){
				tile2 = true;
			}
		}
		return (tile1 && tile2);
	} else if (tileNum == 6 || tileNum == 8 || tileNum == 9){
		for (int i = 0; i < numProperties; i++){
			if (properties[i]->getIndex() == 6){
				tile1 = true;
			} else if (properties[i]->getIndex() == 8){
				tile2 = true;
			} else if (properties[i]->getIndex() == 9){
				tile3 = true;
			}
		}
		return (tile1 && tile2 && tile3);
	} else if (tileNum == 11 || tileNum == 13 || tileNum == 14){
		for (int i = 0; i < numProperties; i++){
			if (properties[i]->getIndex() == 11){
				tile1 = true;
			} else if (properties[i]->getIndex() == 13){
				tile2 = true;
			} else if (properties[i]->getIndex() == 14){
				tile3 = true;
			}
		}
		return (tile1 && tile2 && tile3);
	} else if (tileNum == 16 || tileNum == 18 || tileNum == 19){
		for (int i = 0; i < numProperties; i++){
			if (properties[i]->getIndex() == 16){
				tile1 = true;
			} else if (properties[i]->getIndex() == 18){
				tile2 = true;
			} else if (properties[i]->getIndex() == 19){
				tile3 = true;
			}
		}
		return (tile1 && tile2 && tile3);
	} else if (tileNum == 21 || tileNum == 23 || tileNum == 24){
		for (int i = 0; i < numProperties; i++){
			if (properties[i]->getIndex() == 21){
				tile1 = true;
			} else if (properties[i]->getIndex() == 23){
				tile2 = true;
			} else if (properties[i]->getIndex() == 24){
				tile3 = true;
			}
		}
		return (tile1 && tile2 && tile3);
	} else if (tileNum == 26 || tileNum == 27 || tileNum == 29){
		for (int i = 0; i < numProperties; i++){
			if (properties[i]->getIndex() == 26){
				tile1 = true;
			} else if (properties[i]->getIndex() == 27){
				tile2 = true;
			} else if (properties[i]->getIndex() == 29){
				tile3 = true;
			}
		}
		return (tile1 && tile2 && tile3);
	} else if (tileNum == 31 || tileNum == 32 || tileNum == 34){
		for (int i = 0; i < numProperties; i++){
			if (properties[i]->getIndex() == 31){
				tile1 = true;
			} else if (properties[i]->getIndex() == 32){
				tile2 = true;
			} else if (properties[i]->getIndex() == 34){
				tile3 = true;
			}
		}
		return (tile1 && tile2 && tile3);
	} else if (tileNum == 37 || tileNum == 39){
		for (int i = 0; i < numProperties; i++){
			if (properties[i]->getIndex() == 37){
				tile1 = true;
			} else if (properties[i]->getIndex() == 39){
				tile2 = true;
			}
		}
		return (tile1 && tile2);
	} else {
		return false;
	}
}

bool Player::hasProperty(Tile & t){
	for (int i = 0; i < numProperties; i++){
		if (properties[i]->getName() == t.getName()){
			return true;
		}
	}
	return false;
}

// Buy Property
void Player::addProperty(Tile & t){
	properties[numProperties] = &t;
	numProperties++;
}