#ifndef PLAYER_H
#define PLAYER_H
#include <string>


class Tile;

class Player{
  std::string name;
  std::string piece;
  int money;
  int rollUpCup;
  Tile * pos;
  Tile * properties[];
  int numProperties;
  int DCTimsLine;
  public:

    //CTOR
    Player(std::string name, std::string piece);
    //DTOR
    ~Player();

    //getters
    std::string getName();
    std::string getPiece();
    int getMoney();
    int getNetWorth();
    Tile *getPos();
    int getDCTimsLine();
    int getRollUpCup();

    //Player moves
    void roll();
    void displayAssets();
    void bankrupt(Player * otherPlayer);
    void addMoney(int addition);
    bool subMoney(int subtraction);
    void updatePos(Tile & t);
    void setDCTimsLine(int turns);
    void addRollUpCup();
    void removeRollUpCup();

    //Property functions
    void improve(Tile * t, int numImprovements);
    void unimprove(Tile * t, int numImprovements);
    void mortgage(Tile * t);
    void unmortage(Tile * t);
    bool hasProperty(Tile &t);
    void removeProperty(Tile & t);
    void addProperty(Tile & t);


};

#endif
