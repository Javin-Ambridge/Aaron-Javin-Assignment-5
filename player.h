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
  Tile * properties[40];
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

    //Player moves
    void displayAssets();
    void bankrupt(Player * otherPlayer);
    void trade(Player * otherPlayer);
    void addMoney(int addition);
    bool subMoney(int subtraction);
    void updatePos(Tile & t);
    void setDCTimsLine(int turns);
    void addRollUpCup();
    void removeRollUpCup();
    void setLastDieRoll(int die);
    void setBankrupt(bool b);
    void setMoney(int money);

    //Property functions
    bool ownsBlock(Tile * t);
    bool hasProperty(Tile &t);
    void addProperty(Tile & t);


};

#endif
