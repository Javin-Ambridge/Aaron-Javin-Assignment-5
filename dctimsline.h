#ifndef DCTIMSLINE_H
#define DCTIMSLINE_H
#include "tile.h"

class DCTimsLine: public Tile {
	public:
		DCTimsLine(std::string name);
		virtual ~DCTimsLine();
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
