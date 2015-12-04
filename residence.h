#ifndef RESIDENCE_H
#define RESIDENCE_H
#include "tile.h"
#include "player.h"
#include <string>

class Residence: public Tile {
	Player *players[8];
	Tile *board[40];
	public:
		Residence(std::string n, int ind);
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
		virtual bool getMortgaged();
		virtual void setNumImprovements(int improves);
		virtual void setIndex(int ind);
		virtual void addPlayer(Player *p);
		virtual void addBoard(Tile **boardArray);
		virtual void setMortgaged(bool mortgaged);
		virtual void setAdditionalUnmortgagedFee(bool fee);
		virtual bool getAdditionalUnmortgagedFee();
};

#endif
