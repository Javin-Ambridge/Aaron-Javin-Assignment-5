#include "player.h"
#include "game.h"
#include <cstdlib>
#include <string>

#define MAX_PROPERTIES 40
using namespace std;

//Player constructor for a new player entering the game
Player::Player(string nam, string piec){
	name = nam;
	piece = piec;
	money = 1500;
	rollUpCup = 0;
	pos = NULL;
	numProperties = 0;
	isBankrupt = false;
}

//Player Destructor
Player::~Player(){
}

//GETTERS 
//return the player's name
string Player::getName(){
	return name;
}

//return the player's board piece
string Player::getPiece(){
	return piece;
}

// return the player's current money
int Player::getMoney(){
	return money;
}

//Return net worth taking into account property worth and improvements on properties
int Player::getNetWorth(){
	int netWorth = money;
	for (int i = 0; i < numProperties; i++){
		netWorth += properties[i]->getPurchaseCost();
		netWorth += (properties[i]->getNumImprovements() * properties[i]->getImprovementCost());
	}
	return netWorth;
}

//return the tile the player is currently located at
Tile * Player::getPos(){
	return pos;
}

//return number of turns player has been in DC tims line
int Player::getDCTimsLine(){
	return DCTimsLine;
}

//return number of roll up cups player has
int Player::getRollUpCup(){
	return rollUpCup;
}

//return the last die roll of the player
int Player::getLastDieRoll(){
	return lastDieRoll;
}

//return if the player is bankrupt
bool Player::getBankrupt(){
	return isBankrupt;
}

//return number of properties player has
int Player::getNumProperties(){
	return numProperties;
}

//PLAYER MOVES
//display player's assets
void Player::displayAssets(){
	cout << "Player: " << name << " | Piece: " << piece << endl;
	cout << "Assets:" << endl;
	cout << "Current Money: " << money << endl;
	cout << "Properties owned: " << endl;
	if(numProperties == 0)
		cout << "No Properties owned." << endl;
	for(int i = 0; i < numProperties; i++){
		cout << properties[i]->getName();
		cout << " with " << properties[i]->getNumImprovements() << " improvements" << endl;
	}
	cout << "Number of Roll Up Cups: " <<rollUpCup << endl;
}

//The player has declared bankruptcy and now all assets will be transferred over
void Player::bankrupt(Player * otherPlayer){
	//Transfer whatevery funds left
	otherPlayer->addMoney(money);
	for (int i = 0; i < numProperties; i++){
		otherPlayer->addProperty(*(properties[i]));
	}
	//If the current player owns a rollUpCup and the otherPlayer doesn't, give the otherPlayer the rollUpCup
	if (rollUpCup == 1){
		otherPlayer->addRollUpCup();
	}
	//Player now owns nothing
	money=0;
	numProperties=0;
	rollUpCup=0;
}

//Adds addition to money
void Player::addMoney(int addition){
	money += addition;
}

//Deducts subtraction from player's money
bool Player::subMoney(int subtraction){
	if (money - subtraction < 0){
		cout << "Insufficient funds!" << endl;
		return false;
	}
	money -= subtraction;
	return true;
}

//Updates player position to t
void Player::updatePos(Tile & t){
	pos = &t;
}

//set DCTimsLine to turns
void Player::setDCTimsLine(int turns){
	DCTimsLine = turns;
}

//add 1 rollUpCup to player
void Player::addRollUpCup(){
	rollUpCup = rollUpCup + 1;
}

//remove 1 rollUpCup from player
void Player::removeRollUpCup(){
	rollUpCup = rollUpCup - 1;
}

//set lastDieRoll to die
void Player::setLastDieRoll(int die){
	lastDieRoll = die;
}

//sets player bankrupt to b
void Player::setBankrupt(bool b){
	isBankrupt = b;
}

//sets player money to amount
void Player::setMoney(int amount){
	money = amount;
}

//Determine if player owns entire monopoly block
bool Player::ownsBlock(Tile * t){
	int tileNum = t->getIndex();
	bool tile1 = false;
	bool tile2 = false;
	bool tile3 = false;
	//Block 1
	if (tileNum == 1 || tileNum == 3){
		for (int i = 0; i < numProperties; i++){
			if (properties[i]->getIndex() == 1){
				tile1 = true;
			} else if (properties[i]->getIndex() == 3){
				tile2 = true;
			}
		}
		return (tile1 && tile2);
	}
	//Block 2 
	else if (tileNum == 6 || tileNum == 8 || tileNum == 9){
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
	} 
	///Block 3
	else if (tileNum == 11 || tileNum == 13 || tileNum == 14){
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
	} 
	//Block 4
	else if (tileNum == 16 || tileNum == 18 || tileNum == 19){
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
	} 
	//Block 5
	else if (tileNum == 21 || tileNum == 23 || tileNum == 24){
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
	} 
	//Block 6
	else if (tileNum == 26 || tileNum == 27 || tileNum == 29){
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
	} 
	//Block 7
	else if (tileNum == 31 || tileNum == 32 || tileNum == 34){
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
	} 
	//Block 8
	else if (tileNum == 37 || tileNum == 39){
		for (int i = 0; i < numProperties; i++){
			if (properties[i]->getIndex() == 37){
				tile1 = true;
			} else if (properties[i]->getIndex() == 39){
				tile2 = true;
			}
		}
		return (tile1 && tile2);
	} 
	//Non-Property Tile
	else {
		return false;
	}
}

//Determine if player has a property
//Return true if player has property
//Return false otherwise
bool Player::hasProperty(Tile & t){
	for (int i = 0; i < numProperties; i++){
		if (properties[i]->getName() == t.getName()){
			return true;
		}
	}
	return false;
}

//Trading for giving a Tile and receiving a Tile 
void Player::trade(Tile *give, Tile *recieve, Player *p2){
	this->removeProperty(*give);
	this->addProperty(*recieve);
	p2->removeProperty(*recieve);
	p2->addProperty(*give);
}

//Trading for giving a Tile and receiving Money
void Player::trade(Tile *give, int recieve, Player *p2){
	this->addMoney(recieve);
	this->removeProperty(*give);
	p2->subMoney(recieve);
	p2->addProperty(*give);
}

//Trading for giving money and receiving Tile
void Player::trade(int give, Tile *recieve, Player *p2){
	this->subMoney(give);
	this->addProperty(*recieve);
	p2->subMoney(give);
	p2->removeProperty(*recieve);
}

// Buy Property
void Player::addProperty(Tile & t){
	properties[numProperties] = &t;
	numProperties++;
}

// Removes property from player possession 
bool Player::removeProperty(Tile &t){
	int tileIndex = 101;
	//Check if player has property
	for(int i = 0; i < MAX_PROPERTIES; i++){
		if(properties[i]->getName() == t.getName()){
			tileIndex = i;
			break;
		}
	}
	//If player doesnt have property return false
	if(tileIndex == 101)
		return false;
	int pos = 0;
	//remove tiles from properties array
	for(int i = 0; i < MAX_PROPERTIES; i++){
		if(i < tileIndex){
			pos++;
		}else if(i == tileIndex){
			properties[i] = NULL;
		}else{
			properties[pos] = properties[i];
			pos++;
		}
	}
	numProperties--;
	return true;
}