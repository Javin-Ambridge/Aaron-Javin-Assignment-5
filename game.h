#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include "player.h"
#include "tile.h"
#include "view.h"
#include "propertytile.h"
#include "gym.h"
#include "randomgenerator.h"
#include "residence.h"


class Game {
		Player *players[8];
		int numberOfPlayers;
		int currentRollupCups;
		Tile *board[40];
		int numPlayers;
		bool active;
		bool testing;
		View *view;
		RandomGenerator *generator;
		bool isPlayer(std::string name);
		int isProperGive(std::string give, int playerIndex);
		bool isMortgagable(int playerIndex, std::string propertyName);
		void unMortgage(int playerIndex);
		void bankrupt(int playerIndex, std::string playerOwed);
	public:
		Game(View *v);
		~Game();
		void save(int currentPlayer, std::string fileName, bool hasRolled);
		void load(std::ifstream& ifsInput, int numberOfPlayers);
		bool isActive();
		bool isPieceUsed(std::string piece);
		bool isPlayerActive(std::string name);
		bool isTileOwned(Tile &t);
		int isMember(std::string input);
		Tile *getPosition(int playerIndex);
		int getNumberOfPlayers();
		void setNumberOfPlayers(int num);
		void addPlayer(std::string name, std::string piece);
		void doMove(int playerIndex);
		bool canGetRollup();
		void wonRollup();
		void usedRollup();
		int playerWhoOwns(Tile *t);
		void auction(Tile *t);
		void trade(int playerIndex);
		void mortgage(int playerIndex);
		void buyImprovement(int boardTileInt, int playerIndex);
		void sellImprovement(int boardTileInt, int playerIndex);
		void notEnoughMoney(int balanceNeeded, int playerIndex, std::string playerOwed);
		std::string returnPlayerPiece(int playerIndex);
		void setTesting(bool test);
		int totalBlockImprovements(Tile *t);
};

#endif
