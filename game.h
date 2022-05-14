#ifndef GAME_H
#define GAME_H

#include "chessDisplay.h"
using namespace std;

vector<string> pieces;
int NUM_PIECES = 7;
int PIECE_TOTAL = 16;

// Board dimensions
int BOARD_WIDTH = 9;
int BOARD_HEIGHT = 10;

// Vectors of coordinates, for input/output to textfile
vector<vector<int>> redCoors(16, vector<int>(2, 0));
vector<vector<int>> blackCoors(16, vector<int>(2, 0));

void printIndex() {
  cout << left << setw(15) << "1 - General" << setw(15) << "2 - Guard" << endl;
  cout << setw(15) << "3 - Elephant" << setw(15) << "4 - Horse" << endl;
  cout << setw(15) << "5 - Chariot" << setw(15) << "6 - Cannon" << endl;
  cout << setw(15) << "7 - Soldier" << endl << endl;
}

void defaultCoordinates()
{
  // hard-code default coordinates for black pieces
  blackCoors[0] = {4, 0};
  blackCoors[1] = {3, 0};
  blackCoors[2] = {5, 0};
  blackCoors[3] = {2, 0};
  blackCoors[4] = {6, 0};
  blackCoors[5] = {1, 0};
  blackCoors[6] = {7, 0};
  blackCoors[7] = {0, 0};
  blackCoors[8] = {8, 0};
  blackCoors[9] = {1, 2};
  blackCoors[10] = {7, 2};
  blackCoors[11] = {0, 3};
  blackCoors[12] = {2, 3};
  blackCoors[13] = {4, 3};
  blackCoors[14] = {6, 3};
  blackCoors[15] = {8, 3};


}

int playGame()
{
  defaultCoordinates();

  bool done = false; // when checkmate or end of game(quit/save)
  int pieceChoice;
  int coors[2];
  char confirm;

  pieces.push_back("general");
  pieces.push_back("guard");
  pieces.push_back("elephant");
  pieces.push_back("horse");
  pieces.push_back("chariot");
  pieces.push_back("cannon");
  pieces.push_back("soldier");

  AGAIN:clearScreen();

  while(!done)
  {
    // Replace with index w/ symbols for name of chess pieces
    printIndex();

    printBoard();

    cout << "Enter a piece number, or enter 0 to quit: ";
    cin >> pieceChoice;

    if(pieceChoice == 0)
    {
      return 3;
    }
    while(pieceChoice < 0 || pieceChoice > NUM_PIECES)
    {
      cout << "Invalid piece! Please try again.";
      cin.ignore();
      cin.get();

      cout << "Enter a piece, or enter 0 to quit: ";
      cin >> pieceChoice;

      if(pieceChoice == 0)
      {
        return 3;
      }
    }

    cout << endl << "You chose " << pieces[pieceChoice - 1] << ". Confirm choice[y/n]: ";
    cin >> confirm;

    if(tolower(confirm) == 'y')
    {
      cout << "Enter the new coordinates(x y), with a space in between, or 0 to quit: ";
      cin >> coors[0] >> coors[1];

      if(coors[0] == 0 || coors[1] == 0)
      {
        return 3;
      }

      while(coors[0] < 0 || coors[0] > BOARD_WIDTH || coors[1] < 0 || coors[1] > BOARD_HEIGHT)
      {
        cout << "Invalid piece! Please try again.";
        cin.ignore();
        cin.get();

        cout << "Enter the new coordinates(x y), with a space in between, or 0 to quit: ";
        cin >> coors[0] >> coors[1];

        if(coors[0] == 0 || coors[1] == 0)
        {
          return 3;
        }
      }
    }
    else{
      goto AGAIN;
    }

    //check validity of coordinates here(make sure they're within range of board)
  }
  return 1;
}

void loadGame()
{
  clearScreen();

  ifstream inData;
  inData.open("coordinates.txt");


}

void saveGame()
{

}

#endif
