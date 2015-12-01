#ifndef PROPERTYTILE_H
#define PROPERTYTILE_H
#include "tile.h"

class PropertyTile: public Tile {
	int *improveArray;
	public:
		PropertyTile(std::string n, int purch = 0, int ind = 0, int *improves = NULL, std::string monop = "", int improveC = 0);
		virtual ~PropertyTile();
		virtual bool improveAmount(int improves);
		virtual std::string getName();
		virtual bool isBuyable();
		virtual bool isEvent();
		virtual int getTuition();
		virtual int getPurchaseCost();
		virtual int getImprovementCost();
		virtual std::string getMonopolyBlock();
		virtual int getIndex();
		virtual void setBuyable(bool buyable);
		virtual int getMove(int probability);		
		virtual int getMoneyChange(int probability);
		virtual int getNumImprovements();
		virtual void setNumImprovements();
		virtual void setIndex(int ind);
};

#endif
