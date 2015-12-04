#ifndef GYM_H
#define GYM_H
#define MAX_PROPERTIES 40
#define MAX_PLAYERS 8
#include "tile.h"
#include "player.h"
#include "randomgenerator.h"

class Gym: public Tile {
	Player *players[MAX_PLAYERS];
	Tile *board[MAX_PROPERTIES];
	RandomGenerator *generator;
	public:
		Gym(std::string n, int ind, RandomGenerator *gen);
		virtual ~Gym();
		virtual std::string getName();
		virtual bool isBuyable();
		virtual int getTuition();
		virtual int getPurchaseCost();
		virtual int getImprovementCost();
		virtual int getIndex();
		virtual void setBuyable(bool buy);
		virtual int getMove(int probability);		
		virtual int getMoneyChange(int probability);
		virtual int getNumImprovements();
		virtual bool getMortgaged();
		virtual void setNumImprovements(int improves);
		virtual void setIndex(int ind);
		virtual void addPlayer(Player *p);
		virtual void addBoard(Tile **boardArray);
		virtual void setMortgaged(bool mortgaged);
		virtual void setAdditionalUnmortgagedFee(bool fee);
		virtual bool getAdditionalUnmortgagedFee();
};

#endif
