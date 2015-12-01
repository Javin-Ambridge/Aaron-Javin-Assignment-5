#ifndef GYM_H
#define GYM_H
#include "tile.h"
#include "player.h"
#include "randomgenerator.h"

class Gym: public Tile {
	Player **players;
	Tile **board;
	RandomGenerator *generator;
	public:
		Gym(std::string n, int ind, Player **playerArray, Tile **boardArray, RandomGenerator *gen);
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
		virtual void setBuyable(bool buy);
		virtual int getMove(int probability);		
		virtual int getMoneyChange(int probability);
		virtual int getNumImprovements();
		virtual void setNumImprovements();
		virtual void setIndex(int ind);
};

#endif
