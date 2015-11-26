#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include "player.h"
#include "tile.h"
#include "view.h"


class Game {
		Player *players[8];
		int numberOfPlayers;
		int currentRollupCups;
		Tile *board[40];
		int numPlayers;
		bool active;
		View *view;
	public:
		Game(View *v);
		~Game();
		void save();
		void load();
		bool isActive();
		bool isPieceUsed(std::string piece);
		bool isTileOwned(Tile &t);
		int getNumberOfPlayers();
		void setNumberOfPlayers(int num);
		void addPlayer(std::string name, std::string piece);
		void doMove(int playerIndex);
		bool canGetRollup();
		void wonRollup();
		void usedRollup();
};

#endif
