#include <string>
#include <iostream>
#include "game.h"
#include "propertytile.h"
#include "collectosap.h"
#include "coopfee.h"
#include "dctimsline.h"
#include "goosenesting.h"
#include "gototims.h"
#include "needleshall.h"
#include "slc.h"
#include "tuition.h"
#include "gym.h"
using namespace std;

Game::Game(View *v){
	view = v;
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


Game::~Game(){
	for(int i = 0; i < 40; i++)
		delete board[i];
	for(int i = 0; i < 8; i++){
		if(players[i] != NULL)
			delete players[i];
	}
}
