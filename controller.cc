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
	bool load = false;
	bool testing = false;
	bool fileExists = false;
	ifstream loadFile;
	//argv[0] is the program
	//argv[1] is -load or -testing
	for (int r = 1; r < argc; r++){
		if (strcmp(argv[r], "-load") == 0){
			if (argc > r && strcmp(argv[r], "-testing") == 0 ){ //there exists another command line argument which is not "-testing"
				char* file = argv[r+1];
				loadFile.open(file);
				fileExists = loadFile.good(); //check if file exists
				++r;
			} 
			while (!fileExists){
				cout << "Enter a valid save file or type 'new' for a new game" << endl;
				string file;
				cin >> file;
				if (file == "new"){
					break;
				} else {
					loadFile.open(file.c_str());
					fileExists = loadFile.good(); 
				}
			}
		} else if (strcmp(argv[r], "-testing") == 0) {
			testing = true;
			cout << "Testing mode enabled" << endl;
			cout << "New Roll Command: roll <die1> <die2>" << endl;
			cout << "<die1> and <die2> may be ANY non-negative value and not neccessarily between 1 and 6" << endl;
			currGame->setTesting(true);
		}
	}
	if (fileExists){
		load = true;
		int numPlayers;
		loadFile >> numPlayers;
		currGame->setNumberOfPlayers(numPlayers);
		currView->setNumberOfPlayers(numPlayers);
		currGame->load(loadFile, numPlayers);
		for (int i = 0; i < numPlayers; i++){
			currView->addPlayer(currGame->returnPlayerPiece(i));
			currView->notify(i, currGame->getPosition(i));
		}
		while(currGame->isActive()){ //Play the game.
			for(int i = 0; i < currGame->getNumberOfPlayers(); i++){
				if(!currGame->isActive()){					
					cout << "You have just quit the game. Hopefully you have saved if you wanted to.." << endl;
					break;
				}
				currGame->doMove(i);
				currView->notify(i, currGame->getPosition(i));
				currView->print();
			}
		}
	}
	if (!load){
		cout << "Welcome to BB7K" << endl;
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
			cout << "Enter the name of the player" << endl;
			string name;
			string piece;
			cin >> name;
			cout << "Choose one of the following monopoly pieces:" << endl;
			cout << "| G | B | D | P | S | $ | L | T |" << endl;
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
		currView->print();
		while(currGame->isActive()){ //Play the game.
			for(int i = 0; i < currGame->getNumberOfPlayers(); i++){
				if(!currGame->isActive()){					
					cout << "You have just quit the game. Hopefully you have saved if you wanted to.." << endl;
					break;
				}
				currGame->doMove(i);
				currView->notify(i, currGame->getPosition(i));
				currView->print();
			}
		}
	}
	delete currGame;
	delete currView;
}
