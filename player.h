#ifndef PLAYER_H
#define PLAYER_H
#define MAX_PROPERTIES 40
#include <string>

class Tile;

class Player{
  std::string name;
  std::string piece;
  int money;
  int rollUpCup;
  Tile * pos;
  Tile * properties[MAX_PROPERTIES];
  int numProperties;
  int DCTimsLine;
  int lastDieRoll;
  bool isBankrupt;
  public:

    //CTOR
    Player(std::string nam, std::string piec);
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
    int getLastDieRoll();
    bool getBankrupt();
    int getNumProperties();

    //Player moves
    void displayAssets();
    void bankrupt(Player * otherPlayer);
    void addMoney(int addition);
    bool subMoney(int subtraction);
    void updatePos(Tile & t);
    void setDCTimsLine(int turns);
    void addRollUpCup();
    void removeRollUpCup();
    void setLastDieRoll(int die);
    void setBankrupt(bool b);
    void setMoney(int amount);
    void trade(Tile *give, Tile *recieve, Player *p2);
    void trade(Tile *give, int recieve, Player *p2);
    void trade(int give, Tile *recieve, Player *p2);

    //Property functions
    bool ownsBlock(Tile * t);
    bool hasProperty(Tile &t);
    void addProperty(Tile & t);
    bool removeProperty(Tile &t);

};

#endif
