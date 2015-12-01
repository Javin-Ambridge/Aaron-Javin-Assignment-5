#ifndef RESIDENCE_H
#define RESIDENCE_H
#include "tile.h"
#include "player.h"
#include <string>

class Residence: public Tile {
	Player **players;
	Tile **board;
	public:
		Residence(std::string n, int ind, Player **playerArray, Tile **boardArray);
		virtual ~Residence();
		virtual bool improveAmount(int improves);
		virtual std::string getName();
		virtual bool isBuyable();
		virtual bool isEvent();
		virtual int getTuition();
		virtual int getPurchaseCost();
		virtual int getImprovementCost();
		virtual std::string getMonopolyBlock();
		virtual int getIndex();
		virtual void setBuyable(bool buy);
		virtual int getMove(int probability);		
		virtual int getMoneyChange(int probability);
		virtual int getNumImprovements();
		virtual void setNumImprovements();
		virtual void setIndex(int ind);
};

#endif
