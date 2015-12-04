#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "game.h"
using namespace std;

Game::Game(View *v){
	view = v;
	generator = new RandomGenerator();
	currentRollupCups = 0;
	active = true;
	//string n, int ind, Player **playerArray, Tile **boardArray){
	board[0] = new PropertyTile("Collect OSAP"); 
	board[0]->setIndex(0);
	int ALarray[6] = {2,10,30,90,160,250};
	board[1] = new PropertyTile("AL", 40, 1, ALarray, "Arts1", 50);
	board[2] = new PropertyTile("SLC");
	board[2]->setIndex(2);
	int MLarray[] = {4,20,60,180,320,450};
	board[3] = new PropertyTile("ML",60, 3, MLarray, "Arts1", 50);
	board[4] = new PropertyTile("Tuition");
	board[4]->setIndex(4);
	board[5] = new Residence("MKV", 5); //Residence
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
	board[12] = new Gym("PAC", 12, generator);
	int DWEarray[] = {10,50,150,450,625,750};
	board[13] = new PropertyTile("DWE", 140, 13, DWEarray, "Eng", 100);
	int CPHarray[] = {12,60,180,500,700,900};
	board[14] = new PropertyTile("CPH", 160, 14, CPHarray, "Eng", 100);
	board[15] = new Residence("UWP", 15); //Residence
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
	board[25] = new Residence("V1", 25); //Residence
	int PHYSarray[] = {22,110,330,800,975,1150};
	board[26] = new PropertyTile("PHYS", 260, 26, PHYSarray, "Sci1", 150);
	int B1array[] = {22,110,330,800,975,1150};
	board[27] = new PropertyTile("B1", 260, 27, B1array, "Sci1", 150);
	board[28] = new Gym("CIF", 28, generator);
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
	board[35] = new Residence("REV", 35); //Residence
	board[36] = new PropertyTile("Needles Hall");
	board[36]->setIndex(36);
	int MCarray[] = {35,175,500,1100,1300,1500};
	board[37] = new PropertyTile("MC", 350, 37, MCarray, "Math", 200);
	int COOPFEEarray[] = {150,150,150,150,150,150};
	board[38] = new PropertyTile("Coop Fee", 0, 38, COOPFEEarray);
	int DCarray[] = {50,200,600,1400,1700,2000};
	board[39] = new PropertyTile("DC", 400, 39, DCarray, "Math", 200);
	for(int i = 0; i < 8; i++)
		players[i] = NULL;	
	Residence *tmpMKV = dynamic_cast <Residence *>(board[5]);
	Residence *tmpUWP = dynamic_cast <Residence *>(board[15]);
	Residence *tmpV1 = dynamic_cast <Residence *>(board[25]);
	Residence *tmpREV = dynamic_cast <Residence *>(board[35]);
	tmpMKV->addBoard(board);
	tmpUWP->addBoard(board);
	tmpV1->addBoard(board);
	tmpREV->addBoard(board);
	Gym *tmpPAC = dynamic_cast <Gym *>(board[12]);
	Gym *tmpCIF = dynamic_cast <Gym *>(board[28]);
	tmpPAC->addBoard(board);
	tmpCIF->addBoard(board);
}

void Game::auction(Tile *t){
	int p = this->getNumberOfPlayers();
	int playersIncluded[p];
	int pos = 0;
	for(int i = 0; i < p; i++){
		if(players[i] != NULL){
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
				while(input != "withdraw" && input != "continue"){
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
		notEnoughMoney(currentBid, playersIncluded[finalBidder], "BANK");
		if(players[playersIncluded[finalBidder]]->getBankrupt())
			return;
	}
	players[playersIncluded[finalBidder]]->addProperty(*t);
	t->setBuyable(false);
	cout << "Players new balance is: $" << players[playersIncluded[finalBidder]]->getMoney() << endl;
}

void Game::unMortgage(int playerIndex){
	cout << "Looks like you want to unmortgage something. Please enter a valid building." << endl;
	string property;
	cin >> property;	
	while(!isMortgagable(playerIndex, property) && property != "cancel"){
		cout << "You entered an invalid property. Please try again. (or type cancel to cancel this mortgage)" << endl;
		cin >> property;
	}
	if(property == "cancel"){
		cout << "You have decided to cancel this unmortgage." << endl;
		return;
	}
	int propertyTile;
	for(int i = 0; i < 40; i++){
		if(board[i]->getName() == property){
			propertyTile = i;
			break;
		}
	}
	if(!board[propertyTile]->getMortgaged()){
		cout << "Looks like this property isnt mortgaged, so you obviously can't unmortgage it!" << endl;
		return;
	}
	int costToUnmortgage = board[propertyTile]->getPurchaseCost() * 0.6;
	cout << "It is going to cost you $" << costToUnmortgage << " to unmortgage, are you sure you want to. Yes or No." << endl;
	if(costToUnmortgage > players[playerIndex]->getMoney()){
		cout << "Unoh! You dont have enough money to unmortage this property. Im sorry.." << endl;
		return;
	}
	string input;
	cin >> input;
	while(input != "Yes" && input != "No"){
		cout << "You entered something invalid. Please enter Yes or No." << endl;
		cin >> input;
	}
	if(input == "Yes"){
		cout << "You have decided to unmortage this property, $" << costToUnmortgage << " has been withdrawn from your account." << endl;
		players[playerIndex]->subMoney(costToUnmortgage);
		board[propertyTile]->setMortgaged(false);
		return;
	}else{
		cout << "You have decided that you don't actually want to unmortage." << endl;
		return;
	}
}

void Game::notEnoughMoney(int balanceNeeded, int playerIndex, string playerOwed){	
	cout << "Looks like you don't have enough money! Time to sell some stuff, or declare bankruptcy." << endl;
	cout << "Enter what you would like to do: Declare banckruptcy (bankrupt), trade (trade), mortgage (mortgage) or sell improvements (simprovements)" << endl;
	while(true){
		string input;
		cin >> input;
		while(input != "bankrupt" && input != "trade" && input != "mortgage" && input != "simprovements"){
			cout << "You entered something invalid. Try again. Enter any of bankrupt/trade/mortgage/simprovements" << endl;
			cin >> input;
		}
		if(input == "bankrupt"){
			bankrupt(playerIndex, playerOwed);
		}
		if(input == "trade"){
			trade(playerIndex);
		}
		if(input == "mortgage"){
			mortgage(playerIndex);
		}
		if(input == "simprovements"){			
			cout << "Please enter the property you would like to sell an improvement on." << endl;
			string input2;
			cin >> input2;
			int positionOfInput = isMember(input2);
			while(positionOfInput == -1){
				cout << "You entered an invalid tile name. Try again." << endl;
				cin >> input2;
				positionOfInput = isMember(input2);
			}
			sellImprovement(positionOfInput, playerIndex);
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

void Game::bankrupt(int playerIndex, string playerOwed){
	cout << "Are you sure you want to go bankrupt? If you do this you are out of the game.." << endl;
	cout << "Enter Yes if you want to go bankrupt and No if you want to continue playing." << endl;
	string input;
	cin >> input;
	while(input != "Yes" && input != "No"){
		cout << "You have entered invalid input, please try again. Either Yes or No." << endl;
		cin >> input;
	}
	if(input == "Yes"){
		cout << "Well that sucks... You have went bankrupt! Guess you just need to watch now.." << endl;
		players[playerIndex]->setBankrupt(true);
		return;
	}else{
		cout << "PHEW! You have decided to not go bankrupt. We are continuing on." << endl;
		return;
	}
}

int Game::isProperGive(string give, int playerIndex){
	for(int i = 0; i < 40; i++){
		if(board[i]->getName() == give){
			//Player owns property and block has no improvements
			if(players[playerIndex]->hasProperty(*board[i]) && totalBlockImprovements(board[i]) == 0)
				return -100; //Returns -100 if its a name of piece.
			else
				return -1;
		}
	}
	int stringLen = give.length();
	for(int i = 0; i < stringLen; i++){
		if(give[i] > 57 || give[i] < 48){
			return -1; //Returns -1 if its false.
		}
	}
	istringstream ss(give);
	int amount;
	ss >> amount;
	if(amount > players[playerIndex]->getMoney())
		return -1;
	else
		return amount; //returns the int if its a number
}

bool Game::isPlayer(string name){
	for(int i = 0; i < 8; i++){
		if(players[i] != NULL){
			if(players[i]->getName() == name)
				return true;
		}
	}
	return false;
}

int Game::totalBlockImprovements(Tile *t){
	int tileNum = t->getIndex();
	if (tileNum == 1 || tileNum == 3){
		return board[1]->getNumImprovements() + board[3]->getNumImprovements();
	} else if (tileNum == 6 || tileNum == 8 || tileNum == 9){
		return board[6]->getNumImprovements() + board[8]->getNumImprovements() + board[9]->getNumImprovements();
	} else if (tileNum == 11 || tileNum == 13 || tileNum == 14){
		return board[11]->getNumImprovements() + board[13]->getNumImprovements() + board[14]->getNumImprovements();
	} else if (tileNum == 16 || tileNum == 18 || tileNum == 19){
		return board[16]->getNumImprovements() + board[18]->getNumImprovements() + board[19]->getNumImprovements();
	} else if (tileNum == 21 || tileNum == 23 || tileNum == 24){
		return board[21]->getNumImprovements() + board[23]->getNumImprovements() + board[24]->getNumImprovements();
	} else if (tileNum == 26 || tileNum == 27 || tileNum == 29){
		return board[26]->getNumImprovements() + board[27]->getNumImprovements() + board[29]->getNumImprovements();
	} else if (tileNum == 31 || tileNum == 32 || tileNum == 34){
		return board[31]->getNumImprovements() + board[32]->getNumImprovements() + board[34]->getNumImprovements();
	} else if (tileNum == 37 || tileNum == 39){
		return board[37]->getNumImprovements() + board[39]->getNumImprovements();
	} else { //Return -1 if give a non-property tile
		return -1;
	}
}

void Game::trade(int playerIndex){
	cout << "Please enter the name of the player you want to trade with." << endl;
	cout << "For ease, here are the names of all the players in the game:" << endl;
	for(int i = 0; i < 8; i++){
		if(players[i] != NULL){
			cout << players[i]->getName() << endl;
		}
	}
	cout << "----------------------------------------------------------" << endl;
	string tradeName;
	cin >> tradeName;
	while(!isPlayer(tradeName)){
		cout << "You entered an invalid name, please try again." << endl;
		cin >> tradeName;
	}
	if(tradeName == players[playerIndex]->getName()){
		cout << "Hey! You cant trade with yourself! Canceling this trade." << endl;
		return;
	}
	int player2Index;
	for(int i = 0; i < 8; i++){
		if(players[i] != NULL){			
			if(players[i]->getName() == tradeName){
				player2Index = i;
				break;
			}
		}
	}
	cout << "Please enter what you would like to give to " << tradeName << endl;
	cout << "Note: This has to be either an integer value of money, or a string value of a tile." << endl;
	string give;
	cin >> give;
	int isProperGiveVal = isProperGive(give, playerIndex);
	while(isProperGiveVal == -1){
		cout << "You entered something invalid. Please try again. Ie. Either a name of a property or a number (>0)." << endl;
		cout << "Or you entered a building that you do not own, or more money than you have." << endl;
		cout << "Note: You may not trade any buildings that have improvements." << endl;
		cin >> give;
		isProperGiveVal = isProperGive(give, playerIndex);
	}
	cout << "Now please enter what you want to recieve. Same as above, either a tile or a number (>0)." << endl;
	string recieve;
	cin >> recieve;
	int isProperGiveVal2 = isProperGive(recieve, player2Index);	
	while(isProperGiveVal2 == -1){
		cout << "You entered something invalid. Please try again. Ie. Either a name of a property or a number (>0)." << endl;
		cout << "Or you entered a building that the opposite player does not have, or you entered more money than they have." << endl;
		cout << "Note: You may not trade any buildings that have improvements." << endl;
		cin >> recieve;
		isProperGiveVal2 = isProperGive(recieve, player2Index);
	}
	cout << "This is " << tradeName << " choice now." << endl;
	if(isProperGiveVal == -100){
		if(isProperGiveVal2 == -100){
			//Both are buildings
			cout << "Would you like to trade this building: " << recieve << " for this building: " << give << endl;
			cout << "Please enter Yes or No." << endl;
			string input;
			cin >> input;
			while(input != "Yes" && input != "No"){
				cout << "You entered something invalid. Please try again. Yes or No." << endl;
				cin >> input;
			}
			if(input == "Yes"){
				int giveTile = -1;
				int recieveTile = -1;
				for(int i = 0; i < 40; i++){
					if(giveTile != -1 && recieveTile != -1)
						break;
					if(board[i]->getName() == give)
						giveTile = i;
					if(board[i]->getName() == recieve)
						recieveTile = i;
				}
				players[playerIndex]->trade(board[giveTile], board[recieveTile], players[player2Index]);
				cout << "You have successfully switched properties. Congrats!" << endl;
				return;
			}else{
				cout << tradeName << " has decided to turn down this trade." << endl;
				return;
			}
		}else{
			//give is a building but recieve is a number.
			cout << "Would you like to pay $" << isProperGiveVal2 << " for the following building: " << give << endl;
			cout << "Please enter Yes or No." << endl;
			string input;
			cin >> input;
			while(input != "Yes" && input != "No"){
				cout << "You entered something invalid. Please try again. Yes or No." << endl;
				cin >> input;
			}
			if(input == "Yes"){
				int giveTile;
				for(int i = 0; i < 40; i++){
					if(board[i]->getName() == give){
						giveTile = i;
						break;
					}
				}
				players[playerIndex]->trade(board[giveTile], isProperGiveVal2, players[player2Index]);
				cout << "Success full trade." << endl;
				return;
			}else{
				cout << tradeName << " has decided to turn down this trade." << endl;
				return;
			}
		}
	}else{
		if(isProperGiveVal2 == -100){
			//Give is a value, and recieve is a building.
			cout << "Would you like to sell " << recieve << " for $" << isProperGiveVal << endl;
			cout << "Please enter Yes or No." << endl;
			string input;
			cin >> input;
			while(input != "Yes" && input != "No"){
				cout << "You entered something invalid. Please try again. Yes or No." << endl;
				cin >> input;
			}
			if(input == "Yes"){
				int recieveTile;
				for(int i = 0; i < 40; i++){
					if(board[i]->getName() == recieve){
						recieveTile = i;
						break;
					}
				}
				players[playerIndex]->trade(isProperGiveVal, board[recieveTile], players[player2Index]);
			}else{
				cout << tradeName << " has turned down this trade." << endl;
				return;
			}
		}else{
			//Both are values.
			cout << "Would you like to trade $" << recieve << " for $" << give << endl;
			cout << "Please enter Yes or No." << endl;
			string input;
			cin >> input;
			while(input != "Yes" && input != "No"){
				cout << "You entered something invalid. Please try again. Yes or No." << endl;
				cin >> input;
			}
			if(input == "Yes"){
				players[playerIndex]->subMoney(isProperGiveVal);
				players[playerIndex]->addMoney(isProperGiveVal2);
				players[player2Index]->subMoney(isProperGiveVal2);
				players[player2Index]->addMoney(isProperGiveVal);
				cout << "This trade has been successfull. Congrats." << endl;		
			}else{
				cout << tradeName << " has turned down this trade." << endl;
				return;
			}
		}
	}
}

bool Game::isMortgagable(int playerIndex, string propertyName){
	for(int i = 0; i < 40; i++){
		if(board[i]->getName() == propertyName){
			if(players[playerIndex]->hasProperty(*board[i]))
				return true;
			else
				return false;
		}
	}
	return false;
}

void Game::mortgage(int playerIndex){
	cout << "Looks like you want to mortgage one of your properties. Please enter a valid property you own or enter cancel." << endl;
	string property;
	cin >> property;
	while(!isMortgagable(playerIndex, property) && property != "cancel"){
		cout << "You entered an invalid property. Please try again. (or type cancel to cancel this mortgage)" << endl;
		cin >> property;
	}
	if(property == "cancel"){
		cout << "You have cancelled this mortgage." << endl;
		return;
	}
	int propertyTile;
	for(int i = 0; i < 40; i++){
		if(board[i]->getName() == property){
			propertyTile = i;
			break;
		}
	}
	int totalBlockImproves = totalBlockImprovements(board[propertyTile]);
	if(totalBlockImproves != 0 || totalBlockImproves == -1){
		cout << "Looks like this property, or one in the monopoly block has improvements on it. You need to sell these before you can mortgage it." << endl;
		return;
	}
	int costBack = board[propertyTile]->getPurchaseCost() * 0.5;
	cout << "Are you sure that you want to mortgage this property? Yes or No. You will get $" << costBack << " if you do." << endl;
	string input;
	cin >> input;
	while(input != "Yes" && input != "No"){
		cout << "You entered something incorrectly, try again. Yes or No." << endl;
		cin >> input;
	}
	if(input == "Yes"){
		cout << "You have decided to mortgage this property, $" << costBack << " has been deposited in your account." << endl;
		board[propertyTile]->setMortgaged(true);
		players[playerIndex]->addMoney(costBack);
		return;
	}else{
		cout << "You have changed your mind, this property is no longer getting mortgaged." << endl;
		return;
	}
}

void Game::buyImprovement(int boardTileInt, int playerIndex){
	int purchaseableImprovements[22] = {1,3,6,8,9,11,13,14,16,18,19,21,23,24,26,27,29,31,32,34,37,39};
	bool canImprove = false;
	for(int i = 0; i < 22; i++){
		if(purchaseableImprovements[i] == boardTileInt){
			canImprove = true;
			break;
		}
	}
	if(canImprove == false){
		cout << "Sorry this tile you cannot add improvements on." << endl;
		return;
	}
	if(players[playerIndex]->ownsBlock(board[boardTileInt]) == false)
		canImprove = false;
	if(canImprove == false){
		cout << "Looks like you don't own all of the monopoly blocks in this family, you need to own them all to improve." << endl;
		return;
	}
	int currentNumImprovements = board[boardTileInt]->getNumImprovements();
	if(currentNumImprovements == 5){
		cout << "Looks like you have already bought the max amount of improvements possible." << endl;
		return;
	}
	cout << "Looks like you can successfully improve this tile. You already have this many improvements: " << currentNumImprovements << endl;
	cout << "Please enter a number that is between " << currentNumImprovements + 1 << " and " << 5 << endl;
	cout << "Note that the cost of an improvement on this tile is: $" << board[boardTileInt]->getImprovementCost() << endl;
	int improveAmount = 0;
	cin >> improveAmount; 
	while(improveAmount < currentNumImprovements + 1 || improveAmount > 5){
		cout << "Improper input, please try again. Between " << currentNumImprovements + 1 << " and " << 5 << endl;
		cin >> improveAmount;
	}
	int costForImproves = (improveAmount - currentNumImprovements) * board[boardTileInt]->getImprovementCost();
	cout << "The cost of these improvements is $" << costForImproves << " is this ok? (Yes/No)" << endl;
	string input;
	cin >> input;
	while(input != "Yes" && input != "No"){
		cout << "Improper input please try again. Yes or No." << endl;
		cin >> input;
	} 
	if(input == "No"){
		cout << "Looks like you have changed your mind." << endl;
		return;
	}
	cout << "Good choice, removing the money from your account right now, and improving this tile." << endl;
	if(players[playerIndex]->subMoney(costForImproves) == false){
		notEnoughMoney(150, playerIndex, "BANK");
		if(players[playerIndex]->getBankrupt())
			return;
	}
	board[boardTileInt]->setNumImprovements(improveAmount - currentNumImprovements);
	cout << "Congragulations you have improved this Tile, it now has " << board[boardTileInt]->getNumImprovements() << " improvements." << endl;
	cout << "Your new balance is: $" << players[playerIndex]->getMoney() << endl;
}

void Game::sellImprovement(int boardTileInt, int playerIndex){
	int numImproves = board[boardTileInt]->getNumImprovements();
	if(numImproves == 0){
		cout << "Looks like you can't sell any improvements, ie. the number of improvements on this tile is already 0." << endl;
		return;
	}
	//Selling improvements only give you half of the money back
	int improveCost = (board[boardTileInt]->getImprovementCost()) / 2;
	cout << "How many improvements would you like to sell, currently you have: " << numImproves << endl;
	cout << "You will get $" << improveCost << " for every improvement you sell." << endl;
	cout << "Please enter the number of improvements you want to sell. Enter something that is 0 < x <= " << numImproves << endl;
	int improvesToSell;
	cin >> improvesToSell;
	while(improvesToSell <= 0 || improvesToSell > numImproves){
		cout << "You entered some number that is invalid. Try again. Enter something that is 0 < x <= " << numImproves << endl;
		cin >> improvesToSell;
	}
	int amountBack = improvesToSell * improveCost;
	cout << "Removing " << improvesToSell << " improvements, and depositing $" << amountBack << " into your account." << endl;
	improvesToSell = improvesToSell * -1;
	board[boardTileInt]->setNumImprovements(improvesToSell);
	players[playerIndex]->addMoney(amountBack);
	cout << "Your new balance is: $" << players[playerIndex]->getMoney() << endl;
}

void Game::save(int currentPlayer, string fileName, bool hasRolled){
	const char *cFileName = fileName.c_str();
	ofstream saveFile;
	saveFile.open(cFileName);
	saveFile << numberOfPlayers << endl;
	//Player Save Data
	int startFrom;
	if (hasRolled){ // If player has rolled start at the next player
		startFrom = (currentPlayer + 1) % numberOfPlayers;
	} else {	//else if player has NOT yet rolled start from them
		startFrom = currentPlayer;
	}
	int leftToAdd = numberOfPlayers;
	while (leftToAdd > 0){
		saveFile << players[startFrom]->getName() << " ";
		saveFile << players[startFrom]->getPiece() << " ";
		saveFile << players[startFrom]->getRollUpCup() << " ";
		saveFile << players[startFrom]->getMoney() << " ";
		saveFile << players[startFrom]->getPos()->getIndex();
		if (players[startFrom]->getPos()->getIndex() == 10){ //If Player is on DC Tims Line tile
			if (players[startFrom]->getDCTimsLine() == 0){ //Player is not actually in DC Tims line
				saveFile << " 0" << endl;
			}
			else if (players[startFrom]->getDCTimsLine() > 0){
				saveFile << " 1 "; //Player is in DC Tims Line
				saveFile << players[startFrom]->getDCTimsLine() << endl; 
			}
		}
		else{
			saveFile << endl;
		}
		leftToAdd--;
		startFrom = ((startFrom + 1) % numberOfPlayers);
	}
	//Property save data
	for (int k = 0; k < 40; k++){
	Tile *currentTile = board[k];
		string tileName = currentTile->getName();
		if (tileName !=  "Collect OSAP" && tileName != "SLC" && tileName !=  "Tuition" && tileName !=  "Needles Hall" 
			&& tileName !=  "DC Tims Line" && tileName !=  "Goose Nesting" && tileName !=  "Go To Tims" && tileName !=  "Coop Fee") { // ONLY list property tiles
			saveFile << currentTile->getName() << " ";
			if (currentTile->isBuyable()){ //Tile not owned
				saveFile << "BANK ";
			} else if (currentTile->isBuyable() == false){ // Tile is owned by some player
				saveFile << players[playerWhoOwns(currentTile)]->getName() << " ";
			} 
			// print number of improvements
			if (currentTile->getMortgaged()) { 
				saveFile << -1 << endl; //If building is mortgage print -1 numImprovements
			} else { // else print numImprovements
				saveFile << currentTile->getNumImprovements() << endl;
			}
		}
	}
	saveFile.close();
}

void Game::load(ifstream& ifsInput, int numberOfPlayers){
	ifstream& loadFile = ifsInput;	string name, piece;
	int money, pos, timsCard, inTims, turnsInTims;

	//Loading player data
	for (int i = 0; i < numberOfPlayers; i++){
		loadFile >> name;
		loadFile >> piece;
		loadFile >> timsCard;
		loadFile >> money;
		loadFile >> pos;
		if(players[i] == NULL){
			players[i] = new Player(name, piece);
			if (timsCard){
				players[i]->addRollUpCup();
			}
			players[i]->setMoney(money);
			players[i]->updatePos(*board[pos]);
			if (pos == 10){
				loadFile >> inTims;
				if (inTims == 1){
					loadFile >> turnsInTims;
					players[i]->setDCTimsLine(turnsInTims);
				}
				else {
					turnsInTims = 0;
				}
			}
		}
	}
	//Loading Tile data
	string buildingName, owner;
	int numImproves;
	for (int k = 0; k < 40; k ++){
        if (k == 0 || k == 2 || k == 4 || k == 7 || k == 10 || k == 17
            || k == 20 || k == 22 || k == 30 || k == 33 || k == 36 || k == 38) {
            continue;
        }
        loadFile >> buildingName;
        loadFile >> owner;
        for (int j = 0; j < numberOfPlayers; j++){
        	if(players[j]->getName() == owner){
        		players[j]->addProperty(*board[k]);
        		board[k]->setBuyable(false);
        	}
        }
        loadFile >> numImproves;
        if (numImproves < 0){
        	board[k]->setMortgaged(true);
        } else {
        	board[k]->setMortgaged(false);
			board[k]->setNumImprovements(numImproves);
        }
	}
}


bool Game::isActive(){
	return active;
}

void Game::addPlayer(string name, string piece){
	for(int i = 0; i < 8; i++){
		if(players[i] == NULL){
			players[i] = new Player(name, piece);
			players[i]->updatePos(*board[0]);
			Residence *tmpMKV = dynamic_cast <Residence *>(board[5]);
			Residence *tmpUWP = dynamic_cast <Residence *>(board[15]);
			Residence *tmpV1 = dynamic_cast <Residence *>(board[25]);
			Residence *tmpREV = dynamic_cast <Residence *>(board[35]);
			tmpMKV->addPlayer(players[i]);
			tmpUWP->addPlayer(players[i]);
			tmpV1->addPlayer(players[i]);
			tmpREV->addPlayer(players[i]);
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

int Game::isMember(string input){
	for(int i = 0; i < 40; i++){
		if(board[i]->getName() == input)
			return i;
	}
	return -1;
}

void Game::doMove(int playerIndex){
	Player *currentPlayer = players[playerIndex];
	bool hasRolled = false;
	int doublesRolled = 0;
	bool justGotOutOfDCLine = false;
	cout << "It is " << currentPlayer->getName() << "'s turn.." << endl;
	if(currentPlayer->getBankrupt()){
		cout << "Looks like he is bankrupt. Continuing on." << endl;
		return;
	}
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
				int roll1, roll2;
				if (testing){
					cout << "Testing Roll 1: Enter your two desired dice rolls" << endl;
					cin >> roll1;
					cin >> roll2;
				} else {
					cout << "Rolling two dice right now!" << endl;	
					roll1 = generator->getDiceRoll(); 
					roll2 = generator->getDiceRoll();
				}
				cout << "You rolled a " << roll1 << " for you first roll, and a " << roll2 << " for your second roll." << endl;
				if(roll1 == roll2 && doublesRolled == 2){
					cout << "UHOH you rolled 3 doubles in a row! That means you are going to the DC Tims Line!" << endl;
					currentPlayer->setLastDieRoll(roll1 + roll2);
					currentPlayer->updatePos(*board[10]);
					currentPlayer->setDCTimsLine(1);
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
				int roll1, roll2;
				if (testing){
					cout << "Testing Roll: Enter your two desired dice rolls" << endl;
					cin >> roll1;
					cin >> roll2;
				} else {
					cout << "Rolling two dice right now!" << endl;	
					roll1 = generator->getDiceRoll();
					roll2 = generator->getDiceRoll();
				}
				cout << "You rolled a " << roll1 << " on your first roll, and a " << roll2 << " on the second roll." << endl;
				if(roll1 == roll2){
					cout << "You got a double! Thats pretty lucky! You are now not in the DC Tims Line." << endl;
					currentPosition = currentPosition + roll1 + roll2;
					currentPlayer->setDCTimsLine(0);
				}else{
					cout << "You didnt roll a double.. Looks like your still in the Tims Line. " << endl;
					currentPlayer->setLastDieRoll(roll1 + roll2);
				}
			}else{
				cout << "Using you last roll, which is: " << currentPlayer->getLastDieRoll() << endl;
				currentPosition = currentPosition + currentPlayer->getLastDieRoll();
				justGotOutOfDCLine = false;
			}
			if (currentPosition > 39){
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
					if(changeOfPos < 0){
						changeOfPos = changeOfPos * -1;
						if(currentPosition - changeOfPos < 0){
							int tmpNum = currentPosition - changeOfPos;
							tmpNum = tmpNum * -1;
							currentPosition = 40 - tmpNum;
						}else
							currentPosition = currentPosition - changeOfPos;
					}else
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
				cout << "You have landed on Go To Tims, your are being sent to the DC Tims Line... Sorry..." << endl;
				hasRolled = true;				
				currentPlayer->updatePos(*board[10]);
				view->notify(playerIndex, currentPlayer->getPos());	
				continue;
			}
			if(currentTile->getName() == "Coop Fee"){
				view->notify(playerIndex, currentPlayer->getPos());
				cout << "UHOH! You landed on coop fee." << endl;
				if(currentPlayer->subMoney(currentTile->getTuition()) == false){
					notEnoughMoney(150, playerIndex, "BANK");
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
						notEnoughMoney(300, playerIndex, "BANK");
						if(currentPlayer->getBankrupt())
							return;
					}
					cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;	
				}else{	
					cout << "You chose to pay the 10%, which is $" << tenPercSavingsPay << endl;
					if(currentPlayer->subMoney(tenPercSavingsPay) == false){
						notEnoughMoney(savingsPay, playerIndex, "BANK");
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
					cout << "It is your " << currentTurn - 1 << " turn in the DC Tims Line" << endl;
					if(currentTurn == 4){
						cout << "This is your last turn in the line, you need to pay $50 or use a rollup the rim cup" << endl;
						if(currentPlayer->getRollUpCup() == 0){
							cout << "Sadly you dont have any Roll up the rim cups, so you need to pay $50" << endl;
							if(currentPlayer->subMoney(50) == false){
								notEnoughMoney(50, playerIndex, "BANK");
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
									notEnoughMoney(50, playerIndex, "BANK");
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
									notEnoughMoney(50, playerIndex, "BANK");
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
									notEnoughMoney(50, playerIndex, "BANK");
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
						notEnoughMoney(moneyChange, playerIndex, "BANK");
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
			if(currentTile->isBuyable() && !currentPlayer->hasProperty(*currentTile)){
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
						notEnoughMoney(purchaseCost, playerIndex, "BANK");
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
					auction(currentTile); //Need to update the view after this.
					currentPlayer->updatePos(*currentTile);
					view->notify(playerIndex, currentPlayer->getPos());
					hasRolled = true;
					continue;
				}
			}else if(currentPlayer->hasProperty(*currentTile)){
				cout << "Looks like you have landed on your own tile. This is free parking." << endl;
				hasRolled = true;
				currentPlayer->updatePos(*currentTile);
				view->notify(playerIndex, currentPlayer->getPos());				
				continue;
			}else{
				if(currentTile->getMortgaged()){
					cout << "Looks like its your lucky day, this tile was mortgaged. You don't need to pay anything." << endl;
					hasRolled = true;
					currentPlayer->updatePos(*currentTile);
					view->notify(playerIndex, currentPlayer->getPos());
					continue;					
				}
				cout << "You have landed on the following tile: " << currentTile->getName() << endl;
				cout << "UHOH! Someone owns this property, you need to pay them!" << endl;
				int playerOwner = playerWhoOwns(currentTile);
				int moneyToPay = currentTile->getTuition();
				if (players[playerOwner]->ownsBlock(currentTile) && currentTile->getNumImprovements() == 0){
					//Tuition is doubled if monopoly is owned by there are no improvements on tile
					moneyToPay = currentTile->getTuition() * 2;
				} else {
					moneyToPay = currentTile->getTuition();
				}
				cout << "You are paying " << players[playerOwner]->getName() << " this much money: $" << moneyToPay << endl;
				players[playerOwner]->addMoney(moneyToPay);
				if(currentPlayer->subMoney(moneyToPay) == false){
					notEnoughMoney(moneyToPay, playerIndex, players[playerOwner]->getName());
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
			trade(playerIndex);
			continue;
		}
		if(command == "improve"){
			cout << "Please enter the property you would like to improve on." << endl;
			string input;
			cin >> input; //Property to be bought or sold.
			int positionOfInput = isMember(input);
			while(positionOfInput == -1){
				cout << "You entered an invalid tile name. Try again." << endl;
				cin >> input;
				positionOfInput = isMember(input);
			}
			cout << "Please enter if you would like to buy or sell it (buy/sell)." << endl;
			string buyOrSell;
			cin >> buyOrSell;
			while(buyOrSell != "buy" && buyOrSell != "sell"){
				cout << "You entered an invalid argument. Try again. Enter either buy or sell." << endl;
				cin >> buyOrSell;
			}
			if(buyOrSell == "buy"){
				buyImprovement(positionOfInput, playerIndex);
			}else if(buyOrSell == "sell"){
				sellImprovement(positionOfInput, playerIndex);
			}
			continue;
		}
		if(command == "mortgage"){
			mortgage(playerIndex);
			continue;
		}
		if(command == "unmortgage"){
			unMortgage(playerIndex);
			continue;
		}
		if(command == "assets"){
			currentPlayer->displayAssets();
			continue;
		}
		if(command == "save"){
			cout << "Enter the filename that you wish to save followed by the extensoin  '.txt'" << endl;
			string fileName;
			cin >> fileName;
			save(playerIndex, fileName, hasRolled);
			cout << "Save successful! Your save file is in: " << fileName << endl;
		}
		if(command == "quit"){
			cout << "You have just quit the game. Hopefully you have saved if you wanted to.." << endl;
			active = false;
			return;
		}
		view->print();
	}
}

void Game::setNumberOfPlayers(int num){
	numberOfPlayers = num;
}

void Game::setTesting(bool test){
	testing = test;
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

string Game::returnPlayerPiece(int playerIndex){
	if(players[playerIndex] != NULL){
		return (players[playerIndex]->getPiece());
	}
	return "";
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
