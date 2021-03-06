#ifndef VIEW_H
#define VIEW_H
#include <string>
#include "tile.h"

class Tile;

class View {
	//Tile *positions[8];
	int numPlayers;
    int numPieces;
	std::string currPieces[8];
    int currPiecesPos[8];
	public:
		void print();
		void notify(int playerIndex, Tile *t);
		void setNumberOfPlayers(int num);
		void addPlayer(std::string piece); //sets up the positions as well as the piece info (positions start at GO)
        void removePlayer(std::string piece);
		~View();
        View();
};

#endif
