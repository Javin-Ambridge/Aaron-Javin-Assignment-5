#ifndef COOPFEE_H
#define COOPFEE_H
#include "tile.h"

class CoopFee: public Tile {
	public:
		CoopFee(std::string name);
		virtual ~CoopFee();
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
