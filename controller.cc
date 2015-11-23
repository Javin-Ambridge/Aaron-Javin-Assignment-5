#include <string>
#include <iostream>
#include "controller.h"
using namespace std;

void Controller::startFromSave(string fileName){
	//Implement this later.
}

int main(){
	currGame = new Game();
	currView = new View();

	string input;
	cout << "Specify number of players, or import save state" << endl;
	cin >> input;
	if(input == "-load"){
		cin >> input;
		startFromSave(input);
	}else{
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
				for(int k = 0; k < 8; k++){
					if(players[k] != NULL){
						if(currGame->isPieceUsed(piece))
							continue;
					}
				}
				break;
			}
			currGame->addPlayer(name, piece);
			currView->addPlayer(piece);
		}
	}
	while(currGame->isActive()){ //Play the game.
		for(int i = 0; i < currGame->getNumberOfPlayers(); i++){
			if(!currGame->isActive())
				break;
			currGame->doMove(i);
			currView->notify(i, currGame->getPosition(i));
		}
	}
}