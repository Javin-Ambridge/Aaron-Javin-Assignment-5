#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <string>
#include "player.h"

class Player;

class Controller {
	void startFromSave(std::string fileName);
	Game *currGame;
	View *currView;
	public:

};


#endif
