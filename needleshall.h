#ifndef NEEDLESHALL_H
#define NEEDLESHALL_H
#include "tile.h"

class NeedlesHall: public Tile {
	public:
		NeedlesHall(std::string name);
		virtual ~NeedlesHall();
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
};

#endif
