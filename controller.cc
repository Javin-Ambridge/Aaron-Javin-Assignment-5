#include <string>
#include <iostream>
#include "controller.h"
using namespace std;

void Controller::startFromSave(string fileName){

}

int main(){
	Player *players[8];
	for(int i = 0; i < 8; i++)
		players[i] = NULL;

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
		numberOfPlayers = tmp;
		for(int i = 1; i <= numberOfPlayers; i++){
			cout << "enter name of player followed by piece" << endl;
			string name;
			string piece;
			cin >> name;
			while(true){
				cin >> piece;
				for(int k = 0; k < 8; k++){
					if(players[k] != NULL){
						if(players[k]->getPiece() == piece)
							continue;
					}
				}
				break;
			}
			players[i] = new Player(name, piece);
		}
	}
	while(true){ //Play the game.

	}
}