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
		void save(int currentPlayer, std::string fileName, bool hasRolled);
		bool isPlayerActive(std::string name);
		bool isTileOwned(Tile &t);
		int isMember(std::string input);
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
		int totalBlockImprovements(Tile *t);
	public:
		Game(View *v);
		~Game();
		bool isActive();
		int getNumberOfPlayers();
		bool isWon();
		void setNumberOfPlayers(int num);
		void addPlayer(std::string name, std::string piece);
		void doMove(int playerIndex);
		bool isPieceUsed(std::string piece);
		void setTesting(bool test);
		std::string winner();
		std::string returnPlayerPiece(int playerIndex);
		Tile *getPosition(int playerIndex);
		void load(std::ifstream& ifsInput, int numberOfPlayers);
};

#endif
