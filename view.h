#ifndef VIEW_H
#define VIEW_H
#include <string>
#include "tile.h"

class Tile;

class View {
	Tile positions[];
	int numPlayers;
	std::string currPieces[];
	public:
		void print();
		void notify(Tile pos[]);
		void setNumberOfPlayers(int num);
		void addPlayer(std::string piece);
		~View();
};

#endif
