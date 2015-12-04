#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include "player.h"
#include "game.h"
#include "view.h"
using namespace std;

int main(int argc, char* argv[]){
	View *currView = new View();
	Game *currGame = new Game(currView);
	bool load = false;
	bool fileExists = false;
	ifstream loadFile;
	//argv[0] is the program
	//argv[r] is -load or -testing
	for (int r = 1; r < argc; r++){
		if (strcmp(argv[r], "-load") == 0){
			if (r + 1 < argc && strcmp(argv[r+1], "-testing") != 0 ){  //there exists another command line argument which is not "-testing"
				char* file = argv[r+1];
				loadFile.open(file);
				fileExists = loadFile.good(); //check if file exists
				++r; //argv[r+1] was an invalid input, ++r to move to next command line argument
			} 
			while (!fileExists){
				cout << "Enter a valid save file or type 'new' for a new game" << endl;
				string file;
				cin >> file;
				if (file == "new"){ // if player types new start new game
					break;
				} else { //else check if file name exists
					loadFile.open(file.c_str());
					fileExists = loadFile.good(); 
				}
			}
		} else if (strcmp(argv[r], "-testing") == 0) { // Enter testing mode if -testing command given
			cout << "Testing mode enabled" << endl;
			currGame->setTesting(true);
		}
	}
	if (fileExists){ //if controller loaded a file
		load = true;
		int numPlayers;
		loadFile >> numPlayers;	//get number of players
		currGame->setNumberOfPlayers(numPlayers); // set number of players in game
		currView->setNumberOfPlayers(numPlayers); // set number of players in view
		currGame->load(loadFile, numPlayers);	//call load method of game to initialize game data
		for (int i = 0; i < numPlayers; i++){ //add pieces to the game
			currView->addPlayer(currGame->returnPlayerPiece(i));
			currView->notify(i, currGame->getPosition(i));
		}
		while(currGame->isActive()){ //Play the game.
			for(int i = 0; i < currGame->getNumberOfPlayers(); i++){
				if(!currGame->isActive()){					
					cout << "You have just quit the game. Hopefully you have saved if you wanted to..." << endl;
					break;
				}
				currGame->doMove(i);								// player performs move
				currView->notify(i, currGame->getPosition(i));		// view is updated
				currView->print();									// view is printed
			}
		}
	}
	if (!load){
		cout << "Welcome to BB7K" << endl;
		string input;
		cout << "Specify number of players (enter an integer 1-8)" << endl;
		int tmp;
		cin >> tmp; //Number of players
		while(tmp < 1 || tmp > 8 || cin.fail()){ // check for invalid number of player input
			cout << "Invalid number of players entered" << endl;
			if (cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Please only enter integers from [1-8]" << endl;
			}
			cout << "Try again" << endl;
			cin >> tmp;
		}
		currGame->setNumberOfPlayers(tmp);		//set number of players for game
		currView->setNumberOfPlayers(tmp);		//set number of players for view
		for(int i = 1; i <= tmp; i++){
			cout << "Enter the name of the player" << endl;
			string name;
			string piece;
			cin >> name;
			cout << "Choose one of the following monopoly pieces:" << endl;
			cout << "| G | B | D | P | S | $ | L | T |" << endl;
			while(true){				// check for invalid game piece input
				cin >> piece;
				if (piece != "G" && piece != "B" && piece != "D" && piece != "P" && piece != "S" && piece != "$" && piece != "L" && piece != "T"){
					cout << "That is not a valid piece, try again" << endl;
					continue;
				} else if(currGame->isPieceUsed(piece)){
					cout << "That piece is already used, try again" << endl;
					continue;
				}
				break;
			}
			currGame->addPlayer(name, piece);	// add game piece to game
			currView->addPlayer(piece);			// add game piece to view
		}
		currView->print();
		int initPlayers = currGame->getNumberOfPlayers();
		while(currGame->isActive()){ //Play the game.
			for(int i = 0; i < initPlayers; i++){
				if(!currGame->isActive()){					//player has quit the game
					cout << "You have just quit the game. Hopefully you have saved if you wanted to..." << endl;
					break;
				}
				currGame->doMove(i);								//perform player's turn
				currView->notify(i, currGame->getPosition(i));		//update view
				currView->print();									//notify view
			}
		}
	}
	//game has finished
	if(currGame->isWon()){
		string pWinner = currGame->winner();
		cout << "Congragulations to " << pWinner << " for winning the game!" << endl;
		cout << "What a fun game to play! And to make! Hope you enjoyed yourself!" << endl;
		cout << "--------------------------------------------------------------------------" << endl;
		cout << "                                        Credits." << endl;
		cout << "The game was completely designed and created by Javin Ambridge, and Aaron Lau." << endl;
		cout << "This game was created for CS246 final assignment (Ie. Assignment 5). Which hopefully we will get 100% on." << endl;
		cout << endl << "Thanks for playing!" << endl;
	}
	//delete currView and currGame to prevent memory leaks
	delete currGame;
	delete currView;
}
