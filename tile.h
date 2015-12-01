#ifndef TILE_H
#define TILE_H
#include <string>

class Tile {
	protected:
		bool buyable;
		bool event;
		std::string name;
		int index;
		int tuition;
		int purchaseCost;
		int improvementCost;
		int numImprovements;
		std::string monopolyBlock;
	public:
		virtual ~Tile();
		virtual bool improveAmount(int improves)=0;
		virtual std::string getName()=0;
		virtual bool isBuyable()=0;
		virtual bool isEvent()=0;
		virtual int getTuition()=0;
		virtual int getPurchaseCost()=0;
		virtual int getImprovementCost()=0;
		virtual std::string getMonopolyBlock()=0;
		virtual int getIndex()=0;
		virtual void setBuyable(bool buy)=0;
		virtual int getMove(int probability)=0;		
		virtual int getMoneyChange(int probability)=0;
		virtual int getNumImprovements()=0;
		virtual void setNumImprovements()=0;
};

#endif
