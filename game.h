#ifndef GAME_H
#define GAME_H

#include "chessDisplay.h"
using namespace std;

bool saved = false;

void printIndex() {
  cout << left << setw(15) << "1 - General" << setw(15) << "2 - Guard" << endl;
  cout << setw(15) << "3 - Elephant" << setw(15) << "4 - Horse" << endl;
  cout << setw(15) << "5 - Chariot" << setw(15) << "6 - Cannon" << endl;
  cout << setw(15) << "7 - Soldier" << endl << endl;
}

int playGame(int status)
{

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

    printBoard(status);

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

  ifstream inData;
  inData.open("coordinates.txt");

  for(int x = 0; x < 16; x++)
  {
    for(int y = 0; y < 2; y++)
    {
      inData >> blackCoors[x][y];
    }
    inData >> blackCoors[x][2];
  }
}

void saveGame()
{
  ofstream outData;
  outData.open("coordinates.txt");

  for(int x = 0; x < 16; x++)
  {
    for(int y = 0; y < 2; y++)
    {
      outData << blackCoors[x][y] << " ";
    }
    outData << blackCoors[x][2] << endl;
  }
}

#endif
