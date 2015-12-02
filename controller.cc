#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include "player.h"
#include "game.h"
#include "view.h"
using namespace std;

void startFromSave(string fileName){

}

int main(int argc, char* argv[]){
	View *currView = new View();
	Game *currGame = new Game(currView);
	bool load = false;;

	if (argc > 1 && strcmp(argv[1], "-load") == 0){
		string file = argv[2];
		ifstream loadFile(file.c_str(), ifstream::in);
		bool fileExists = loadFile.good(); //check if file exists
		while (!fileExists){
			cout << "Invalid file name. Re-enter the file name or type 'new' for a new game" << endl;
			cin >> file;
			if (file == "new"){
				break;
			} else {
				ifstream loadFile(file.c_str(), ifstream::in);
				bool fileExists = loadFile.good(); 
			}
		}
		if (fileExists){
			load = true;
			//DO LOADING HERE
		}
	} else if (!load){
		string input;
		cout << "Specify number of players (enter an integer 1-8)" << endl;
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
			cout << "Enter name of player followed by piece" << endl;
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
	}
	delete currGame;
	delete currView;
}
