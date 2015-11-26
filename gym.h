#ifndef GYM_H
#define GYM_H
#include "tile.h"

class Gym: public Tile {
	public:
		Gym(std::string name);
		virtual ~Gym();
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
