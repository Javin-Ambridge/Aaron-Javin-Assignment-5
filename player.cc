#include "player.h"
#include "game.h"
#include <cstdlib>

Player::Player(string, string piece){
	name = name;
	piece = piece;
	money = 1500;
	netWorth = 1500;
	rollUpCup = false;
	properties = NULL;
	pos = board [0];
}

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
	return netWorth;
}

Tile * Player::getPos(){
	return pos;
}

void Player::addMoney(int addition){
	money += addtion;
	netWorth += additon;
}

bool Player::subMoney(int subtraction){
	if (money - subtraction < 0){
		cout << "Insufficient funds!" << endl;
		return false;
	}
	money -= subtraction;
	netWorth -= subtraction;
	return true;
}
