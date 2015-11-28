#include "player.h"
#include "game.h"
#include <cstdlib>
#include <string>

Player::Player(string name, string piece){
	name = name;
	piece = piece;
	money = 1500;
	rollUpCup = false;
	properties = NULL;
	numProperties = 0;
	pos = board [0];
	DCTimsLine = 0;
}

string Player::getName(){
	return name;
}

string Player::getPiece(){
	return piece;
}

int Player::getDCTimsLine(){
	return DCTimsLine;
}

void Player::setDCTimsLine(int turns){
	DCTimsLine = turns;
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

void Player::roll(){
	int die1 = rand() % 6 + 1;
	int die2 = rand() % 6 + 1;
	int sum = die1 + die2;
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


void Player::improve(Tile * t){
	Player *owner = t->getOwner;
	//owner exists, owner is current player, block is owned
	if (owner && owner->getPiece() == this->piece && ownsBlock(t) && t->getNumImprovements() <= 4){
		subMoney(t->getImprovementCost());
		t->setNumImprovements(t->getNumImprovements()+1)
		t->setImp
	} else {
		cout << "You cannot buy improvements" << endl;
	}
}
