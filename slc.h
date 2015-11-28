#ifndef SLC_H
#define SLC_H
#include "tile.h"

class SLC: public Tile {
	public:
		SLC(std::string name);
		virtual ~SLC();
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
		virtual int setNumImprovements();
};

#endif
