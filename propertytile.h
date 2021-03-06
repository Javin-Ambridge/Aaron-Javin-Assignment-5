#ifndef PROPERTYTILE_H
#define PROPERTYTILE_H
#include "tile.h"

class PropertyTile: public Tile {
	int improveArray[6];
	public:
		PropertyTile(std::string n, int purch = 0, int ind = 0, int *improves = NULL, std::string monop = "", int improveC = 0);
		virtual ~PropertyTile();
		virtual std::string getName();
		virtual bool isBuyable();
		virtual int getTuition();
		virtual int getPurchaseCost();
		virtual int getImprovementCost();
		virtual int getIndex();
		virtual void setBuyable(bool buyable);
		virtual int getMove(int probability);		
		virtual int getMoneyChange(int probability);
		virtual int getNumImprovements();
		virtual bool getMortgaged();
		virtual void setNumImprovements(int improves);
		virtual void setIndex(int ind);
		virtual void setMortgaged(bool mortgage);
		virtual void setAdditionalUnmortgagedFee(bool fee);
		virtual bool getAdditionalUnmortgagedFee();
};

#endif
