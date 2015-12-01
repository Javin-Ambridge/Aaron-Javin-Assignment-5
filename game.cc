#include <string>
#include <iostream>
#include "game.h"
using namespace std;

Game::Game(View *v){
	view = v;
	generator = new RandomGenerator();
	currentRollupCups = 0;
	active = true;
	//string n, int ind, Player **playerArray, Tile **boardArray){
	board[0] = new PropertyTile("Collect OSAP");
	int ALarray[] = {2,10,30,90,160,250};
	board[1] = new PropertyTile("AL", 40, 1, ALarray, "Arts1", 50);
	board[2] = new PropertyTile("SLC");
	board[2]->setIndex(2);
	int MLarray[] = {4,20,60,180,320,450};
	board[3] = new PropertyTile("ML",60, 3, MLarray, "Arts1", 50);
	board[4] = new PropertyTile("Tuition");
	board[4]->setIndex(4);
	board[5] = new Residence("MKV", 5, players, board); //Residence
	int ECHarray[] = {6,30,90,270,400,550};
	board[6] = new PropertyTile("ECH", 100, 6, ECHarray, "Arts2", 50); 
	board[7] = new PropertyTile("Needles Hall");
	board[7]->setIndex(7);
	int PASarray[] = {6,30,90,270,400,550};
	board[8] = new PropertyTile("PAS", 100, 8, PASarray, "Arts2", 50);
	int HHarray[] = {8,40,100,300,450,600};
	board[9] = new PropertyTile("HH", 120, 9, HHarray, "Arts2", 50);
	board[10] = new PropertyTile("DC Tims Line");
	board[10]->setIndex(10);
	int RCHarray[] = {10,50,150,450,625,750};
	board[11] = new PropertyTile("RCH", 140, 11, RCHarray, "Eng", 100);
	board[12] = new Gym("PAC", 12, players, board, generator);
	int DWEarray[] = {10,50,150,450,625,750};
	board[13] = new PropertyTile("DWE", 140, 13, DWEarray, "Eng", 100);
	int CPHarray[] = {12,60,180,500,700,900};
	board[14] = new PropertyTile("CPH", 160, 14, CPHarray, "Eng", 100);
	board[15] = new Residence("UWP", 15, players, board); //Residence
	int LHIarray[] = {14,70,200,550,750,950};
	board[16] = new PropertyTile("LHI", 180, 16, LHIarray, "Health", 100);
	board[17] = new PropertyTile("SLC");
	board[17]->setIndex(17);
	int BMHarray[] = {14,70,200,550,750,950};
	board[18] = new PropertyTile("BMH",180, 18, BMHarray, "Health", 100);
	int OPTarray[] = {16,80,220,600,800,1000};
	board[19] = new PropertyTile("OPT", 200, 19, OPTarray, "Health", 100);
	board[20] = new PropertyTile("Goose Nesting");
	board[20]->setIndex(20);
	int EV1array[] = {18,90,250,700,875,1050};
	board[21] = new PropertyTile("EV1", 220, 21, EV1array, "Env", 150);
	board[22] = new PropertyTile("Needles Hall");
	board[22]->setIndex(22);
	int EV2array[] = {18,90,250,700,875,1050};
	board[23] = new PropertyTile("EV2",220,23, EV2array, "Env", 150);
	int EV3array[] = {20,100,300,750,925,1100};
	board[24] = new PropertyTile("EV3", 240, 24, EV3array, "Env", 150);
	board[25] = new Residence("V1", 25, players, board); //Residence
	int PHYSarray[] = {22,110,330,800,975,1150};
	board[26] = new PropertyTile("PHYS", 260, 26, PHYSarray, "Sci1", 150);
	int B1array[] = {22,110,330,800,975,1150};
	board[27] = new PropertyTile("B1", 260, 27, B1array, "Sci1", 150);
	board[28] = new Gym("CIF", 28, players, board, generator);
	int B2array[] = {24,120,360,850,1025,1200};
	board[29] = new PropertyTile("B2", 280, 29, B2array, "Sci1", 150);
	board[30] = new PropertyTile("Go To Tims");
	board[30]->setIndex(30);
	int EITarray[] = {26,130,390,900,1100,1275};
	board[31] = new PropertyTile("EIT", 300, 31, EITarray, "Sci2", 200);
	int ESCarrray[] = {26,130,390,900,1100,1275};
	board[32] = new PropertyTile("ESC", 300, 32, ESCarrray, "Sci2", 200);
	board[33] = new PropertyTile("SLC");
	board[33]->setIndex(33);
	int C2array[] = {28,150,450,1000,1200,1400};
	board[34] = new PropertyTile("C2", 320, 34, C2array, "Sci2", 200);
	board[35] = new Residence("REV", 35, players, board); //Residence
	board[36] = new PropertyTile("Needles Hall");
	board[36]->setIndex(36);
	int MCarray[] = {35,175,500,1100,1300,1500};
	board[37] = new PropertyTile("MC", 350, 37, MCarray, "Math", 200);
	board[38] = new PropertyTile("Coop Fee");
	board[38]->setIndex(38);
	int DCarray[] = {50,200,600,1400,1700,2000};
	board[39] = new PropertyTile("DC", 400, 39, DCarray, "Math", 200);
	for(int i = 0; i < 8; i++)
		players[i] = NULL;
}

void Game::auction(Tile *t, int playerNotIncluded){
	int p = this->getNumberOfPlayers() - 1;
	int playersIncluded[p];
	int pos = 0;
	for(int i = 0; i < p; i++){
		if(i != playerNotIncluded && players[i] != NULL){
			playersIncluded[pos] = i;
			pos++;
		}
	}
	cout << "The following tile is now up for auction: " << t->getName() << endl;
	int playersLeft = p;
	int currentBid = 1;
	while(true){
		if(playersLeft == 1)
			break;
		for(int i = 0; i < p; i++){
			if(playersLeft == 1)
				break;
			if(playersIncluded[i] != -1){
				cout << "It is " << players[playersIncluded[i]]->getName() << " turn to make a bid." << endl;
				string input;
				cout << "Would you like to withdraw from this bidding? Type 'withdraw'or 'continue'" << endl;
				cin >> input;
				while(input != "withdraw" || input != "continue"){
					cout << "You entered an invalid command. Enter either 'withdraw' or 'continue'" << endl;
					cin >> input;
				}
				if(input == "withdraw"){
					playersIncluded[i] = -1;
					playersLeft--;
					continue;
				}
				cout << "You have chosen to bid. Place a bid which is higher than $" << currentBid << endl;
				int bid;
				cin >> bid;
				while(bid <= currentBid){
					cout << "You entered a bid that is lower, or equal to the previous bid. Try again." << endl;
					cin >> bid;
				}
				currentBid = bid;
				cout << "You have just placed the bid of $" << currentBid << endl;
			}
		}
	}
	int finalBidder;
	for(int i = 0; i < p; i++){
		if(playersIncluded[i] != -1){
			finalBidder = i;
			break;
		}
	}
	cout << "Congragulations to " << players[playersIncluded[finalBidder]]->getName() << " you have won the auction with the bid of $" << currentBid << endl;
	cout << players[playersIncluded[finalBidder]]->getName() << " now owns " << t->getName() << endl;
	if(players[playersIncluded[finalBidder]]->subMoney(currentBid) == false){
		notEnoughMoney(currentBid, playersIncluded[finalBidder]);
		if(players[playersIncluded[finalBidder]]->getBankrupt())
			return;
	}
	players[playersIncluded[finalBidder]]->addProperty(*t);
	cout << "Players new balance is: $" << players[playersIncluded[finalBidder]]->getMoney() << endl;
}

void Game::notEnoughMoney(int balanceNeeded, int playerIndex){	
	cout << "Looks like you don't have enough money! Time to sell somestuff, or declare bankruptcy." << endl;
	cout << "Enter what you would like to do: Declare banckruptcy (bankrupt), trade (trade), mortgage (mortgage) or sell improvements (simprovements)" << endl;
	while(true){
		string input;
		cin >> input;
		while(input != "bankrupt" || input != "trade" || input != "mortgage" || input != "simprovements"){
			cout << "You entered something invalid. Try again. Enter any of bankrupt/trade/mortgage/simprovements" << endl;
			cin >> input;
		}
		if(input == "bankrupt"){

		}
		if(input == "trade"){

		}
		if(input == "mortgage"){

		}
		if(input == "simprovements"){

		}
		if(players[playerIndex]->getMoney() >= balanceNeeded){
			cout << "Good job, you have enough money!" << endl;
			break;
		}
		if(players[playerIndex]->getBankrupt()){
			cout << "Looks like your bankrupt and out of the game." << endl;
			break;
		}
	}
}

void Game::bankrupt(){

}

void Game::trade(){

}

void Game::mortgage(){

}

void Game::buyImprovement(string tileName){

}

void Game::sellImprovement(string tileName){

}

bool Game::isActive(){
	return active;
}

void Game::addPlayer(string name, string piece){
	for(int i = 0; i < 8; i++){
		if(players[i] == NULL){
			players[i] = new Player(name, piece);
			players[i]->updatePos(*board[0]);
			return;
		}
	}
}

int Game::playerWhoOwns(Tile *t){
	for(int i = 0; i < 8; i++){
		if(players[i] != NULL){
			if(players[i]->hasProperty(*t))
				return i;
		}
	}
	return -1;
}

void Game::doMove(int playerIndex){
	Player *currentPlayer = players[playerIndex];
	bool hasRolled = false;
	int doublesRolled = 0;
	bool justGotOutOfDCLine = false;
	cout << "It is " << currentPlayer->getName() << "'s turn.." << endl;
	while(true){
		string command;
		cout << endl;
		if(doublesRolled == 0 && justGotOutOfDCLine == false){			
			cout << "Please enter a valid command:" << endl;
			cin >> command;
		}else{
			command = "roll";
			hasRolled = false;
		}
		if(command == "roll"){
			if(hasRolled){
				cout << "You have already rolled, you cannot use this command this turn." << endl;
				continue;
			}			
			int currentPosition = currentPlayer->getPos()->getIndex();
			if(currentPlayer->getDCTimsLine() == 0 && justGotOutOfDCLine == false){	
				cout << "Rolling two dice right now!" << endl;			
				int roll1 = generator->getDiceRoll(); 
				int roll2 = generator->getDiceRoll();
				cout << "You rolled a " << roll1 << " for you first roll, and a " << roll2 << " for your second roll." << endl;
				if(roll1 == roll2 && doublesRolled == 2){
					cout << "UHOH you rolled 3 doubles in a row! That means you are going to the DC Tims Line!" << endl;
					currentPlayer->setLastDieRoll(roll1 + roll2);
					currentPlayer->updatePos(*board[10]);
					hasRolled = true;
					doublesRolled = 0;
					continue;
				}
				if(roll1 == roll2){
					cout << "You just rolled a double, you get to roll again after you do whatever action is for this turn." << endl; 
					doublesRolled++;
				}else{
					doublesRolled = 0;
				}
				int rollNum = roll1 + roll2;
				currentPlayer->setLastDieRoll(rollNum);
				currentPosition = currentPosition + rollNum;
			}else if(currentPlayer->getDCTimsLine() != 0 && justGotOutOfDCLine == false){
				cout << "Rolling two dice to see if you get a double, so you get leave the DC Tims line." << endl;
				int roll1 = generator->getDiceRoll();
				int roll2 = generator->getDiceRoll();
				cout << "You rolled a " << roll1 << " on your first roll, and a " << roll2 << " on the second roll." << endl;
				if(roll1 == roll2){
					cout << "You got a double! Thats pretty lucky! You are now not in the DC Tims Line." << endl;
					currentPosition = currentPosition + roll1 + roll2;
				}else{
					cout << "You didnt roll a double.. Looks like your still in the Tims Line. " << endl;
					currentPlayer->setLastDieRoll(roll1 + roll2);
				}
			}else{
				cout << "Using you last roll, which is: " << currentPlayer->getLastDieRoll() << endl;
				currentPosition = currentPosition + currentPlayer->getLastDieRoll();
			}
			if(currentPosition > 39){
				cout << "----------------------------------------------------------------------" << endl;
				cout << "Congragulations you have passed collect OSAP (or landed on it), you gain $200!" << endl;
				currentPlayer->addMoney(200);
				cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
				cout << "----------------------------------------------------------------------" << endl;
				currentPosition = currentPosition - 40;
			}
			Tile *currentTile = board[currentPosition];
			currentPlayer->updatePos(*currentTile);
			bool DCTimsLineFromSLC = false;
			if(currentTile->getName() == "SLC"){
				view->notify(playerIndex, currentPlayer->getPos());
				if(currentRollupCups < 4){
					if(generator->wonRollupCup()){
						cout << "Congragulations you have won a Rollup the Rim Cup! Thats pretty lucky!" << endl;
						currentPlayer->addRollUpCup();
						currentRollupCups++;
						cout << "You now have " << currentPlayer->getRollUpCup() << " roll up cups." << endl;
						cout << "Your turn is up now." << endl;
						hasRolled = true;
						currentPlayer->updatePos(*currentTile);
						view->notify(playerIndex, currentPlayer->getPos());
						continue;
					}
				}
				int changeOfPos = currentTile->getMove(generator->getSLCRoll());
				if(changeOfPos == 23){
					cout << "SLC probabilities have moved you to the DC Tims Line... Unfortunate.." << endl;
					currentPosition = 10;
					currentPlayer->setDCTimsLine(1);
					DCTimsLineFromSLC = true;
				}
				else if(changeOfPos == 24){
					cout << "SLC probabilities have moved you to colled OSAP! Thats lucky...." << endl;
					currentPosition = 0;
					cout << "----------------------------------------------------------------------" << endl;
					cout << "Congragulations you have landed on Collect OSAP, you gain $200!" << endl;
					currentPlayer->addMoney(200);
					cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
					cout << "----------------------------------------------------------------------" << endl;
				}else{
					cout << "SLC probabilities have move you this many spaces: " << changeOfPos << endl;
					currentPosition = currentPosition + changeOfPos;
				}
				if(currentPosition > 39){
					cout << "----------------------------------------------------------------------" << endl;
					cout << "Congragulations you have passed collect OSAP, you gain $200!" << endl;
					currentPlayer->addMoney(200);
					cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
					cout << "----------------------------------------------------------------------" << endl;
					currentPosition = currentPosition - 40;
				}
				currentTile = board[currentPosition];
				currentPlayer->updatePos(*currentTile);
				view->notify(playerIndex, currentPlayer->getPos());				
			}
			if(currentTile->getName() == "Go To Tims"){
				currentPlayer->setDCTimsLine(1);
				currentPlayer->updatePos(*board[10]);
				view->notify(playerIndex, currentPlayer->getPos());	
				cout << "You have landed on Go To Tims, your are being sent to the DC Tims Line... Sorry..." << endl;
				hasRolled = true;				
				currentPlayer->updatePos(*currentTile);
				view->notify(playerIndex, currentPlayer->getPos());
				continue;
			}
			if(currentTile->getName() == "Coop Fee"){
				view->notify(playerIndex, currentPlayer->getPos());
				cout << "UHOH! You landed on coop fee." << endl;
				if(currentPlayer->subMoney(currentTile->getTuition()) == false){
					notEnoughMoney(150, playerIndex);
					if(currentPlayer->getBankrupt())
						return;
				}
				hasRolled = true;
				cout << "$150 has been removed from your account" << endl;
				cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
				currentPlayer->updatePos(*currentTile);
				view->notify(playerIndex, currentPlayer->getPos());
				continue;
			}
			if(currentTile->getName() == "Tuition"){
				view->notify(playerIndex, currentPlayer->getPos());
				cout << "Looks like you need to pay some tuition, this is either $300 or 10% of your total savings." << endl;
				int savingsPay = currentPlayer->getNetWorth();
				int tenPercSavingsPay = savingsPay * 0.1;
				cout << "To help your decision, here is 10% of your savings: $" << tenPercSavingsPay << endl;
				cout << "So if you want to pay the $300 enter $300 or if you want to pay the 10% enter 10%" << endl;
				string input;
				cin >> input;
				while(input != "$300" && input != "10%"){
					cout << "You entered something incorrect. Try again. ($300 or 10%)" << endl;
					cin >> input;
				}
				if(input == "$300"){
					cout << "You chose to pay the $300" << endl;
					if(currentPlayer->subMoney(300) == false){
						notEnoughMoney(300, playerIndex);
						if(currentPlayer->getBankrupt())
							return;
					}
					cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;	
				}else{	
					cout << "You chose to pay the 10%, which is $" << savingsPay << endl;
					if(currentPlayer->subMoney(tenPercSavingsPay) == false){
						notEnoughMoney(savingsPay, playerIndex);
						if(currentPlayer->getBankrupt())
							return;
					}
					cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
				}
				hasRolled = true;
				currentPlayer->updatePos(*currentTile);
				view->notify(playerIndex, currentPlayer->getPos());
				continue;
			}
			if(currentTile->getName() == "Collect OSAP"){
				view->notify(playerIndex, currentPlayer->getPos());
				cout << "You have landed on Collect OSAP, there is nothing to do." << endl;
				hasRolled = true;
				currentPlayer->updatePos(*currentTile);
				view->notify(playerIndex, currentPlayer->getPos());
				continue;
			}
			if(currentTile->getName() == "Goose Nesting"){
				view->notify(playerIndex, currentPlayer->getPos());
				cout << "You have landed on Goose Nesting, there is nothing to do." << endl;
				hasRolled = true;
				currentPlayer->updatePos(*currentTile);
				view->notify(playerIndex, currentPlayer->getPos());
				continue;
			}
			if(currentTile->getName() == "DC Tims Line"){
				view->notify(playerIndex, currentPlayer->getPos());
				if(currentPlayer->getDCTimsLine() == 0){
					cout << "You landed on DC Tims line, luckily you arent in it!" << endl;
					hasRolled = true;
					currentPlayer->updatePos(*currentTile);
					view->notify(playerIndex, currentPlayer->getPos());
					continue;
				}else{
					cout << "You are in the DC Tims line... You need to do something!" << endl;
					if(DCTimsLineFromSLC == false)
						currentPlayer->setDCTimsLine(currentPlayer->getDCTimsLine() + 1);
					int currentTurn = currentPlayer->getDCTimsLine();
					cout << "It is your " << currentTurn << " turn in the DC Tims Line" << endl;
					if(currentTurn == 4){
						cout << "This is your last turn in the line, you need to pay $50 or use a rollup the rim cup" << endl;
						if(currentPlayer->getRollUpCup() == 0){
							cout << "Sadly you dont have any Roll up the rim cups, so you need to pay $50" << endl;
							if(currentPlayer->subMoney(50) == false){
								notEnoughMoney(50, playerIndex);
								if(currentPlayer->getBankrupt())
									return;
							}
							cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
							hasRolled = true;
							currentPlayer->setDCTimsLine(0);
							justGotOutOfDCLine = true;
							currentPlayer->updatePos(*currentTile);
							view->notify(playerIndex, currentPlayer->getPos());
							continue;
						}else{
							cout << "Looks like you have a Roll up the rim cup." << endl;
							cout << "If you would like to pay the $50 enter $50, or if you want to use the roll up the rim cup enter Rollup" << endl;
							string input;
							cin >> input;
							while(input != "$50" && input != "Rollup"){
								cout << "You entered something incorrectly. Try again. Either $50 or Rollup" << endl;
								cin >> input;
							}
							if(input == "$50"){
								cout << "You chose to spend the $50" << endl;
								if(currentPlayer->subMoney(50) == false){
									notEnoughMoney(50, playerIndex);
									if(currentPlayer->getBankrupt())
										return;
								}	
								cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
							}else{
								cout << "You chose to use a rollup the rim cup." << endl;
								currentPlayer->removeRollUpCup();
								cout << "You have " << currentPlayer->getRollUpCup() << " roll up the rim cups left." << endl;
							}
							currentPlayer->setDCTimsLine(0);
							hasRolled = true;
							justGotOutOfDCLine = true;
							currentPlayer->updatePos(*currentTile);
							view->notify(playerIndex, currentPlayer->getPos());
							continue;
						}
					}else{
						cout << "It is not your last turn in the DC Tims line." << endl;
						cout << "You can either wait, pay $50, or use a rollup the rim cup (You have " << currentPlayer->getRollUpCup() << " cups left)" << endl;
						if(currentPlayer->getRollUpCup() == 0){
							string input;
							cout << "Looks like you don't have any rollup the rim cups. So choose either to Wait or Pay $50 (Wait/$50)" << endl;
							cin >> input;
							while(input != "Wait" && input != "$50"){
								cout << "You entered something incorrectly, please enter either Wait or $50" << endl;
								cin >> input;
							}
							if(input == "Wait"){
								cout << "You chose to wait." << endl;
								hasRolled = true;
								currentPlayer->updatePos(*currentTile);
								view->notify(playerIndex, currentPlayer->getPos());
								continue;
							}else{
								cout << "You chose to spend the $50 and get out of the line." << endl;
								if(currentPlayer->subMoney(50) == false){
									notEnoughMoney(50, playerIndex);
									if(currentPlayer->getBankrupt())
										return;
								}
								cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
								hasRolled = true;
								currentPlayer->setDCTimsLine(0);
								justGotOutOfDCLine = true;		
								currentPlayer->updatePos(*currentTile);	
								view->notify(playerIndex, currentPlayer->getPos());				
								continue;
							}
						}else{
							cout << "Please enter either Wait/$50/Rollup to choose you next move" << endl;
							string input;
							cin >> input;
							while(input != "Wait" && input != "$50" && input != "Rollup"){
								cout << "You entered something incorrectly, please enter either Wait or $50 or Rollup" << endl;
								cin >> input;
							}
							if(input == "Wait"){
								cout << "You chose to wait." << endl;
								hasRolled = true;
								currentPlayer->updatePos(*currentTile);
								view->notify(playerIndex, currentPlayer->getPos());
								continue;
							}else if(input == "$50"){
								cout << "You chose to spend $50 and get out of the DC tims line." << endl;
								if(currentPlayer->subMoney(50) == false){
									notEnoughMoney(50, playerIndex);
									if(currentPlayer->getBankrupt())
										return;
								}
								cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
								hasRolled = true;
								currentPlayer->setDCTimsLine(0);
								justGotOutOfDCLine = true;					
								currentPlayer->updatePos(*currentTile);			
								view->notify(playerIndex, currentPlayer->getPos());
								continue;
							}else{
								cout << "You chose to use a rollup the rim cup." << endl;
								currentPlayer->removeRollUpCup();
								cout << "You have " << currentPlayer->getRollUpCup() << " roll up the rim cups left." << endl;
								hasRolled = true;
								currentPlayer->setDCTimsLine(0);
								justGotOutOfDCLine = true;					
								currentPlayer->updatePos(*currentTile);			
								view->notify(playerIndex, currentPlayer->getPos());
								continue;
							}
						}
					}
				}
			}
			if(currentTile->getName() == "Needles Hall"){ 
				if(currentRollupCups < 4){
					if(generator->wonRollupCup()){
						cout << "Congragulations you have won a Rollup the Rim Cup! Thats pretty lucky!" << endl;
						currentPlayer->addRollUpCup();
						currentRollupCups++;
						cout << "You now have " << currentPlayer->getRollUpCup() << " roll up cups." << endl;
						cout << "Your turn is up now." << endl;
						hasRolled = true;						
						currentPlayer->updatePos(*currentTile);
						view->notify(playerIndex, currentPlayer->getPos());
						continue;
					}
				}
				int moneyChange = currentTile->getMoneyChange(generator->getNeedlesRoll());
				if(moneyChange > 0){
					cout << "Congragulations you just won $" << moneyChange << " from Needles Hall!" << endl;
					currentPlayer->addMoney(moneyChange);
					cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
				}else{
					moneyChange = moneyChange * -1;
					cout << "UHOH! You unfortunately lost $" << moneyChange << " at Needles Hall.." << endl;
					if(currentPlayer->subMoney(moneyChange) == false){
						notEnoughMoney(moneyChange, playerIndex);
						if(currentPlayer->getBankrupt())
							return;
					}
					cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
				}
				hasRolled = true;
				cout << "TRACING:: current tile: " << currentTile->getName() << ", current index: " << currentTile->getIndex() << endl;	
				currentPlayer->updatePos(*currentTile);
				view->notify(playerIndex, currentPlayer->getPos());
				continue;
			}
			if(currentTile->isBuyable()){
				cout << "Looks like this property: " << currentTile->getName() << " is purchasable!" << endl;
				cout << "Would you like to purchase it? The cost of the property is: " << currentTile->getPurchaseCost() << ". Yes/No" << endl;
				string input;
				cin >> input;
				while(input != "Yes" && input != "No"){
					cout << "Invalid input. Please enter Yes or No." << endl;
					cin >> input;
				}
				if(input == "Yes"){
					int purchaseCost = currentTile->getPurchaseCost();
					if(currentPlayer->subMoney(purchaseCost) == false){
						notEnoughMoney(purchaseCost, playerIndex);
						if(currentPlayer->getBankrupt())
							return;
					}
					currentPlayer->addProperty(*currentTile);
					currentTile->setBuyable(false);
					cout << "Congragulations you have just purchased " << currentTile->getName() << endl;
					cout << "Your current balance is now " << currentPlayer->getMoney() << endl;
					hasRolled = true;
					currentPlayer->updatePos(*currentTile);
					view->notify(playerIndex, currentPlayer->getPos());
					continue;
				}else{
					auction(currentTile, playerIndex); //Need to update the view after this.
				}
			}else{
				cout << "You have landed on the following tile: " << currentTile->getName() << endl;
				cout << "UHOH! Someone owns this property, you need to pay them!" << endl;
				int playerOwner = playerWhoOwns(currentTile);
				cout << "You are paying " << players[playerOwner]->getName() << " this much money: $" << currentTile->getTuition() << endl;
				int payableMoney = currentTile->getTuition();
				players[playerOwner]->addMoney(payableMoney);
				if(currentPlayer->subMoney(payableMoney) == false){
					notEnoughMoney(payableMoney, playerIndex);
					if(currentPlayer->getBankrupt())
						return;
				}
				cout << "Your current balance is now: " << currentPlayer->getMoney() << endl;
				hasRolled = true;
				currentPlayer->updatePos(*currentTile);
				view->notify(playerIndex, currentPlayer->getPos());
				continue;
			}
		}
		if(command == "next"){
			if(!hasRolled){
				cout << "Looks like you haven't rolled yet. You need to roll before you continue." << endl;
				continue;
			}else{				
				cout << "Thank you for ending you turn. Continuing to the next player." << endl;
				view->notify(playerIndex, currentPlayer->getPos());
				break;
			}
		}
		if(command == "trade"){
			trade();
		}
		if(command == "improve"){
			string input;
			cin >> input; //Property to be bought or sold.
			string buyOrSell;
			cin >> buyOrSell;
			if(buyOrSell == "buy"){
				buyImprovement(input);
			}else if(buyOrSell == "sell"){
				sellImprovement(input);
			}else{
				//Not entered something correctly.
			}
		}
		if(command == "mortgage"){
			mortgage();
		}
		if(command == "unmortgage"){

		}
		if(command == "assets"){
			currentPlayer->displayAssets();
		}
		if(command == "save"){

		}
		view->print();
	}
}

void Game::setNumberOfPlayers(int num){
	numberOfPlayers = num;
}

int Game::getNumberOfPlayers(){
	return numberOfPlayers;
}

bool Game::isPieceUsed(string piece){
	for(int i = 0; i < 8; i++){
		if(players[i] != NULL){
			if(players[i]->getPiece() == piece)
				return true;
		}
	}
	return false;
}

Tile *Game::getPosition(int playerIndex){
	return players[playerIndex]->getPos();
}

Game::~Game(){
	for(int i = 0; i < 40; i++)
		delete board[i];
	for(int i = 0; i < 8; i++){
		if(players[i] != NULL)
			delete players[i];
	}
	delete generator;
}
