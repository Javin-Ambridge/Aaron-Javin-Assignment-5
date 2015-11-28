#ifndef TUITION_H
#define TUITION_H
#include "tile.h"

class Tuition: public Tile {
	public:
		Tuition(std::string name);
		virtual ~Tuition();
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
