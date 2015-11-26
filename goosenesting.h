#ifndef GOOSENESTING_H
#define GOOSENESTING_H
#include "tile.h"

class GooseNesting: public Tile {
	public:
		GooseNesting(std::string name);
		virtual ~GooseNesting();
		virtual bool improveAmount(int improves);
		virtual std::string getName();
		virtual bool isBuyable();
		virtual bool isEvent();
		virtual int getTuition();
		virtual int getPurchaseCost();
		virtual int getImprovementCost();
		virtual std::string getMonopolyBlock();
		virtual int getIndex();
};

#endif
