#include "view.h"
#include <iostream>
#include <string>
using namespace std;

//Player postion - Tile 
int tile00Pos [8] = {84, 85, 86, 87, 84, 85, 86, 87};
int tile01Pos [8] = {76, 77, 78, 79, 76, 77, 78, 79};
int tile02Pos [8] = {68, 69, 70, 71, 68, 69, 70, 71};
int tile03Pos [8] = {60, 61, 62, 63, 60, 61, 62, 63};
int tile04Pos [8] = {52, 53, 54, 55, 52, 53, 54, 55};
int tile05Pos [8] = {44, 45, 46, 47, 44, 45, 46, 47};
int tile06Pos [8] = {36, 37, 38, 39, 36, 37, 38, 39};
int tile07Pos [8] = {28, 29, 30, 31, 28, 29, 30, 31};
int tile08Pos [8] = {20, 21, 22, 23, 20, 21, 22, 23};
int tile09Pos [8] = {12, 13, 14, 15, 12, 13, 14, 15};
int tile10Pos [8] = {4, 5, 6, 7, 4, 5, 6, 7};

int tile11Pos [8] = {4, 5, 6, 7, 4, 5, 6, 7};
int tile12Pos [8] = {4, 5, 6, 7, 4, 5, 6, 7};
int tile13Pos [8] = {4, 5, 6, 7, 4, 5, 6, 7};
int tile14Pos [8] = {4, 5, 6, 7, 4, 5, 6, 7};
int tile15Pos [8] = {4, 5, 6, 7, 4, 5, 6, 7};
int tile16Pos [8] = {4, 5, 6, 7, 4, 5, 6, 7};
int tile17Pos [8] = {4, 5, 6, 7, 4, 5, 6, 7};
int tile18Pos [8] = {4, 5, 6, 7, 4, 5, 6, 7};
int tile19Pos [8] = {4, 5, 6, 7, 4, 5, 6, 7};
int tile20Pos [8] = {4, 5, 6, 7, 4, 5, 6, 7};

int tile21Pos [8] = {12, 13, 14, 15, 12, 13, 14, 15};
int tile22Pos [8] = {20, 21, 22, 23, 20, 21, 22, 23};
int tile23Pos [8] = {28, 29, 30, 31, 28, 29, 30, 31};
int tile24Pos [8] = {36, 37, 38, 39, 36, 37, 38, 39};
int tile25Pos [8] = {44, 45, 46, 47, 44, 45, 46, 47};
int tile26Pos [8] = {52, 53, 54, 55, 52, 53, 54, 55};
int tile27Pos [8] = {60, 61, 62, 63, 60, 61, 62, 63};
int tile28Pos [8] = {68, 69, 70, 71, 68, 69, 70, 71};
int tile29Pos [8] = {76, 77, 78, 79, 76, 77, 78, 79};
int tile30Pos [8] = {84, 85, 86, 87, 84, 85, 86, 87};

int tile31Pos [8] = {82, 83, 84, 85, 86, 87, 88, 82};
int tile32Pos [8] = {82, 83, 84, 85, 86, 87, 88, 82};
int tile33Pos [8] = {82, 83, 84, 85, 86, 87, 88, 82};
int tile34Pos [8] = {82, 83, 84, 85, 86, 87, 88, 82};
int tile35Pos [8] = {82, 83, 84, 85, 86, 87, 88, 82};
int tile36Pos [8] = {82, 83, 84, 85, 86, 87, 88, 82};
int tile37Pos [8] = {82, 83, 84, 85, 86, 87, 88, 82};
int tile38Pos [8] = {82, 83, 84, 85, 86, 87, 88, 82};
int tile39Pos [8] = {82, 83, 84, 85, 86, 87, 88, 82};

void View::print(){
	string tmpArr[56];
    tmpArr[0]  = "-----------------------------------------------------------------------------------------";
    tmpArr[1]  = "|Goose  |       |NEEDLES|       |       |V1     |       |       |CIF    |       |GO TO  |";
    tmpArr[2]  = "|Nesting|-------|HALL   |-------|-------|       |-------|-------|       |-------|TIMS   |";
    tmpArr[3]  = "|       |EV1    |       |EV2    |EV3    |       |PHYS   |B1     |       |B2     |       |";
    tmpArr[4]  = "|       |       |       |       |       |       |       |       |       |       |       |";
    tmpArr[5]  = "|-------|-----------------------------------------------------------------------|-------|";
    tmpArr[6]  = "|       |                                                                       |       |";
    tmpArr[7]  = "|-------|                                                                       |-------|";
    tmpArr[8]  = "|OPT    |                                                                       |EIT    |";
    tmpArr[9]  = "|       |                                                                       |       |";
    tmpArr[10] = "|-------|                                                                       |-------|";
    tmpArr[11] = "|       |                                                                       |       |";
    tmpArr[12] = "|-------|                                                                       |-------|";
    tmpArr[13] = "|BMH    |                                                                       |ESC    |";
    tmpArr[14] = "|       |                                                                       |       |";
    tmpArr[15] = "|-------|                                                                       |-------|";
    tmpArr[16] = "|SLC    |                                                                       |SLC    |";
    tmpArr[17] = "|       |                                                                       |       |";
    tmpArr[18] = "|       |                                                                       |       |";
    tmpArr[19] = "|       |                                                                       |       |";
    tmpArr[20] = "|-------|                                                                       |-------|";
    tmpArr[21] = "|       |                                                                       |       |";
    tmpArr[22] = "|-------|                                                                       |-------|";
    tmpArr[23] = "|LHI    |                                                                       |C2     |";
    tmpArr[24] = "|       |                                                                       |       |";
    tmpArr[25] = "|-------|                                                                       |-------|";
    tmpArr[26] = "|UWP    |                             BB7K                                      |REV    |";
    tmpArr[27] = "|       |                                                                       |       |";
    tmpArr[28] = "|       |                                                                       |       |";
    tmpArr[29] = "|       |                                                                       |       |";
    tmpArr[30] = "|-------|                                                                       |-------|";
    tmpArr[31] = "|       |                                                                       |NEEDLES|";
    tmpArr[32] = "|-------|                                                                       |HALL   |";
    tmpArr[33] = "|CPH    |                                                                       |       |";
    tmpArr[34] = "|       |                                                                       |       |";
    tmpArr[35] = "|-------|                                                                       |-------|";
    tmpArr[36] = "|       |                                                                       |       |";
    tmpArr[37] = "|-------|                                                                       |-------|";
    tmpArr[38] = "|DWE    |                                                                       |MC     |";
    tmpArr[39] = "|       |                                                                       |       |";
    tmpArr[40] = "|-------|                                                                       |-------|";
    tmpArr[41] = "|PAC    |                                                                       |COOP   |";
    tmpArr[42] = "|       |                                                                       |FEE    |";
    tmpArr[43] = "|       |                                                                       |       |";
    tmpArr[44] = "|       |                                                                       |       |";
    tmpArr[45] = "|-------|                                                                       |-------|";
    tmpArr[46] = "|       |                                                                       |       |";
    tmpArr[47] = "|-------|                                                                       |-------|";
    tmpArr[48] = "|RCH    |                                                                       |DC     |";
    tmpArr[49] = "|       |                                                                       |       |";
    tmpArr[50] = "|-------|-----------------------------------------------------------------------|-------|";
    tmpArr[51] = "|DC Tims|       |       |NEEDLES|       |MKV    |TUITION|       |SLC    |       |COLLECT|";
    tmpArr[52] = "|Line   |-------|-------|HALL   |-------|       |       |-------|       |-------|OSAP   |";
    tmpArr[53] = "|       |HH     |PAS    |       |ECH    |       |       |ML     |       |AL     |       |";
    tmpArr[54] = "|       |       |       |       |       |       |       |       |       |       |       |";
    tmpArr[55] = "-----------------------------------------------------------------------------------------";

    for (int k = 0; k < numPlayers; k++){
        int pos = currPiecesPos[k];
        if (pos == 0){
            if(k <= 4){
                tmpArr[54].replace(tile00Pos[k],1,currPieces[k]);
            } else {
                tmpArr[53].replace(tile00Pos[k],1,currPieces[k]);
            }
        } else if (pos == 1){
            if(k <= 4){
                tmpArr[54].replace(tile01Pos[k],1,currPieces[k]);
            } else {
                tmpArr[53].replace(tile01Pos[k],1,currPieces[k]);
            }
        } else if (pos == 2){
            if(k <= 4){
                tmpArr[54].replace(tile02Pos[k],1,currPieces[k]);
            } else {
                tmpArr[53].replace(tile02Pos[k],1,currPieces[k]);
            }
        } else if (pos == 3){
            if(k <= 4){
                tmpArr[54].replace(tile03Pos[k],1,currPieces[k]);
            } else {
                tmpArr[53].replace(tile03Pos[k],1,currPieces[k]);
            }
        } else if (pos == 4){
            if(k <= 4){
                tmpArr[54].replace(tile04Pos[k],1,currPieces[k]);
            } else {
                tmpArr[53].replace(tile04Pos[k],1,currPieces[k]);
            }
        } else if (pos == 5){
            if(k <= 4){
                tmpArr[54].replace(tile05Pos[k],1,currPieces[k]);
            } else {
                tmpArr[53].replace(tile05Pos[k],1,currPieces[k]);
            }
        } else if (pos == 6){
            if(k <= 4){
                tmpArr[54].replace(tile06Pos[k],1,currPieces[k]);
            } else {
                tmpArr[53].replace(tile06Pos[k],1,currPieces[k]);
            }
        } else if (pos == 7){
            if(k <= 4){
                tmpArr[54].replace(tile07Pos[k],1,currPieces[k]);
            } else {
                tmpArr[53].replace(tile07Pos[k],1,currPieces[k]);
            }
        } else if (pos == 8){
            if(k <= 4){
                tmpArr[54].replace(tile08Pos[k],1,currPieces[k]);
            } else {
                tmpArr[53].replace(tile08Pos[k],1,currPieces[k]);
            }
        } else if (pos == 9){
            if(k <= 4){
                tmpArr[54].replace(tile09Pos[k],1,currPieces[k]);
            } else {
                tmpArr[53].replace(tile09Pos[k],1,currPieces[k]);
            }
        } else if (pos == 10){
            if(k <= 4){
                tmpArr[54].replace(tile10Pos[k],1,currPieces[k]);
            } else {
                tmpArr[53].replace(tile10Pos[k],1,currPieces[k]);
            }
        } else if (pos == 11){
            if(k <= 4){
                tmpArr[49].replace(tile11Pos[k],1,currPieces[k]);
            } else {
                tmpArr[48].replace(tile11Pos[k],1,currPieces[k]);
            }
        } else if (pos == 12){
            if(k <= 4){
                tmpArr[43].replace(tile12Pos[k],1,currPieces[k]);
            } else {
                tmpArr[44].replace(tile12Pos[k],1,currPieces[k]);
            }
        } else if (pos == 13){
            if(k <= 4){
                tmpArr[39].replace(tile13Pos[k],1,currPieces[k]);
            } else {
                tmpArr[38].replace(tile13Pos[k],1,currPieces[k]);
            }
        } else if (pos == 14){
            if(k <= 4){
                tmpArr[34].replace(tile14Pos[k],1,currPieces[k]);
            } else {
                tmpArr[33].replace(tile14Pos[k],1,currPieces[k]);
            }
        } else if (pos == 15){
            if(k <= 4){
                tmpArr[28].replace(tile15Pos[k],1,currPieces[k]);
            } else {
                tmpArr[29].replace(tile15Pos[k],1,currPieces[k]);
            }
        } else if (pos == 16){
            if(k <= 4){
                tmpArr[24].replace(tile16Pos[k],1,currPieces[k]);
            } else {
                tmpArr[23].replace(tile16Pos[k],1,currPieces[k]);
            }
        } else if (pos == 17){
            if(k <= 4){
                tmpArr[18].replace(tile17Pos[k],1,currPieces[k]);
            } else {
                tmpArr[19].replace(tile17Pos[k],1,currPieces[k]);
            }
        } else if (pos == 18){
            if(k <= 4){
                tmpArr[14].replace(tile18Pos[k],1,currPieces[k]);
            } else {
                tmpArr[13].replace(tile18Pos[k],1,currPieces[k]);
            }
        } else if (pos == 19){
            if(k <= 4){
                tmpArr[9].replace(tile19Pos[k],1,currPieces[k]);
            } else {
                tmpArr[8].replace(tile19Pos[k],1,currPieces[k]);
            }
        } else if (pos == 20){
            if(k <= 4){
                tmpArr[4].replace(tile20Pos[k],1,currPieces[k]);
            } else {
                tmpArr[3].replace(tile20Pos[k],1,currPieces[k]);
            }
        } else if (pos == 21){
            if(k <= 4){
                tmpArr[4].replace(tile21Pos[k],1,currPieces[k]);
            } else {
                tmpArr[3].replace(tile21Pos[k],1,currPieces[k]);
            }
        } else if (pos == 22){
            if(k <= 4){
                tmpArr[4].replace(tile22Pos[k],1,currPieces[k]);
            } else {
                tmpArr[3].replace(tile22Pos[k],1,currPieces[k]);
            }
        } else if (pos == 23){
            if(k <= 4){
                tmpArr[4].replace(tile23Pos[k],1,currPieces[k]);
            } else {
                tmpArr[3].replace(tile23Pos[k],1,currPieces[k]);
            }
        } else if (pos == 24){
            if(k <= 4){
                tmpArr[4].replace(tile24Pos[k],1,currPieces[k]);
            } else {
                tmpArr[3].replace(tile24Pos[k],1,currPieces[k]);
            }
        } else if (pos == 25){
            if(k <= 4){
                tmpArr[4].replace(tile25Pos[k],1,currPieces[k]);
            } else {
                tmpArr[3].replace(tile25Pos[k],1,currPieces[k]);
            }
        } else if (pos == 26){
            if(k <= 4){
                tmpArr[4].replace(tile26Pos[k],1,currPieces[k]);
            } else {
                tmpArr[3].replace(tile26Pos[k],1,currPieces[k]);
            }
        } else if (pos == 27){
            if(k <= 4){
                tmpArr[4].replace(tile27Pos[k],1,currPieces[k]);
            } else {
                tmpArr[3].replace(tile27Pos[k],1,currPieces[k]);
            }
        } else if (pos == 28){
            if(k <= 4){
                tmpArr[4].replace(tile28Pos[k],1,currPieces[k]);
            } else {
                tmpArr[3].replace(tile28Pos[k],1,currPieces[k]);
            }
        } else if (pos == 29){
            if(k <= 4){
                tmpArr[4].replace(tile29Pos[k],1,currPieces[k]);
            } else {
                tmpArr[3].replace(tile29Pos[k],1,currPieces[k]);
            }
        } else if (pos == 30){
            if(k <= 4){
                tmpArr[4].replace(tile30Pos[k],1,currPieces[k]);
            } else {
                tmpArr[3].replace(tile30Pos[k],1,currPieces[k]);
            }
        } else if (pos == 31){
            if(k <= 4){
                tmpArr[9].replace(tile31Pos[k],1,currPieces[k]);
            } else {
                tmpArr[8].replace(tile31Pos[k],1,currPieces[k]);
            }
        } else if (pos == 32){
            if(k <= 4){
                tmpArr[14].replace(tile32Pos[k],1,currPieces[k]);
            } else {
                tmpArr[13].replace(tile32Pos[k],1,currPieces[k]);
            }
        } else if (pos == 33){
            if(k <= 4){
                tmpArr[18].replace(tile33Pos[k],1,currPieces[k]);
            } else {
                tmpArr[19].replace(tile33Pos[k],1,currPieces[k]);
            }
        } else if (pos == 34){
            if(k <= 4){
                tmpArr[24].replace(tile34Pos[k],1,currPieces[k]);
            } else {
                tmpArr[23].replace(tile34Pos[k],1,currPieces[k]);
            }
        } else if (pos == 35){
            if(k <= 4){
                tmpArr[28].replace(tile35Pos[k],1,currPieces[k]);
            } else {
                tmpArr[29].replace(tile35Pos[k],1,currPieces[k]);
            }
        } else if (pos == 36){
            if(k <= 4){
                tmpArr[33].replace(tile36Pos[k],1,currPieces[k]);
            } else {
                tmpArr[34].replace(tile36Pos[k],1,currPieces[k]);
            }
        } else if (pos == 37){
            if(k <= 4){
                tmpArr[39].replace(tile37Pos[k],1,currPieces[k]);
            } else {
                tmpArr[38].replace(tile37Pos[k],1,currPieces[k]);
            }
        } else if (pos == 38){
            if(k <= 4){
                tmpArr[43].replace(tile38Pos[k],1,currPieces[k]);
            } else {
                tmpArr[44].replace(tile38Pos[k],1,currPieces[k]);
            }
        } else if (pos == 39){
            if(k <= 4){
                tmpArr[49].replace(tile39Pos[k],1,currPieces[k]);
            } else {
                tmpArr[48].replace(tile39Pos[k],1,currPieces[k]);
            }
        } 
    }

    for (int i = 0; i < 55; i++){
        cout << tmpArr[i] << endl;
    }
}

void View::notify(int playerNum, Tile * t){
    currPiecesPos[playerNum] = t->getIndex();
    print();
}

void View::setNumberOfPlayers(int num){
	numPlayers = num;
}

void View::addPlayer(string piece){
    currPieces[numPieces]=piece;
    numPieces++;
}

void View::removePlayer(string piece){
    for (int i = 0; i < numPlayers; i++){
        if (currPieces[i] == piece){
            for (int j = i; j + 1 < numPlayers; j++){
                currPieces[j] = currPieces[j+1];
                currPiecesPos[j] = currPiecesPos[j+1];
            }
            numPlayers--;
            numPieces--;
            return;
        }
    }
}

View::~View(){
}

View::View(){
    numPlayers = 0;
    numPieces = 0;
    print();
}