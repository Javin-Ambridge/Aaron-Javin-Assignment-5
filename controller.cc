#include <string>
#include <iostream>
#include "player.h"
#include "game.h"
#include "view.h"
using namespace std;

void startFromSave(string fileName){

}

int main(){
	View *currView = new View();
	Game *currGame = new Game(currView);

	string input;
	cout << "Specify number of players, or import save state" << endl;
	int tmp;
	cin >> tmp; //Number of players
	while(tmp < 1 || tmp > 8){
		cout << "Invalid number of players entered" << endl;
		cout << "Try again" << endl;
		cin >> tmp;
	}
	currGame->setNumberOfPlayers(tmp);
	currView->setNumberOfPlayers(tmp);
	for(int i = 1; i <= tmp; i++){
		cout << "enter name of player followed by piece" << endl;
		string name;
		string piece;
		cin >> name;
		while(true){
			cin >> piece;
			if(currGame->isPieceUsed(piece)){
				cout << "That piece is already used, try again" << endl;
				continue;
			}
			break;
		}
		currGame->addPlayer(name, piece);
		currView->addPlayer(piece);
	}
	while(currGame->isActive()){ //Play the game.
		for(int i = 0; i < currGame->getNumberOfPlayers(); i++){
			if(!currGame->isActive())
				break;
			currGame->doMove(i);
			currView->notify(i, currGame->getPosition(i));
			currView->print();
		}
	}
	delete currGame;
	delete currView;
}
