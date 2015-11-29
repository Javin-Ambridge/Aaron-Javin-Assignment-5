#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
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
		View *view;
		RandomGenerator *generator;
	public:
		Game(View *v);
		~Game();
		void save();
		void load();
		bool isActive();
		bool isPieceUsed(std::string piece);
		bool isTileOwned(Tile &t);
		Tile *getPosition(int playerIndex);
		int getNumberOfPlayers();
		void setNumberOfPlayers(int num);
		void addPlayer(std::string name, std::string piece);
		void doMove(int playerIndex);
		bool canGetRollup();
		void wonRollup();
		void usedRollup();
		int playerWhoOwns(Tile *t);
		void auction(Tile *t, int playerNotIncluded);
		void trade();
		void bankrupt();
		void mortgage();
		void buyImprovement(std::string tileName);
		void sellImprovement(std::string tileName);
		void notEnoughMoney(int balanceNeeded, int playerIndex);
};

#endif
