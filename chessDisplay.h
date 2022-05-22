#ifndef CHESS_DISPLAY_H
#define CHESS_DISPLAY_H

#include "enums.h"
#include "chessBoardSpot.h"
using namespace std;

// Stores char of spots on chessbaord
vector<vector<char>> boardChars(10, vector<char>(9, '*'));

vector<string> pieces; // stores string of pieces
int NUM_PIECES = 7; // constant for piece numbers
int PIECE_TOTAL = 16; // constant for total pieces per team

// Board dimensions
int BOARD_WIDTH = 9;
int BOARD_HEIGHT = 10;

// Vectors of coordinates, for input/output to textfile
// vector<vector<int>> redCoors(16, vector<int>(3, 0));
// vector<vector<int>> blackCoors(16, vector<int>(3, 0));

void clearSpots(ChessBoardSpot** spots)
{

}

void defaultCoordinates(ChessBoardSpot** spots)
{
  // hard-code default coordinates for black pieces
  // blackCoors[0] = {4, 0, 1};
  // blackCoors[1] = {3, 0, 2};
  // blackCoors[2] = {5, 0, 2};
  // blackCoors[3] = {2, 0, 3};
  // blackCoors[4] = {6, 0, 3};
  // blackCoors[5] = {1, 0, 4};
  // blackCoors[6] = {7, 0, 4};
  // blackCoors[7] = {0, 0, 5};
  // blackCoors[8] = {8, 0, 5};

  // blackCoors[9] = {1, 2, 6};
  // blackCoors[10] = {7, 2, 6};
  // blackCoors[11] = {0, 3, 7};
  // blackCoors[12] = {2, 3, 7};
  // blackCoors[13] = {4, 3, 7};
  // blackCoors[14] = {6, 3, 7};
  // blackCoors[15] = {8, 3, 7};


  // Note that the x and y coordinates are swapped for the spots array; spots[y][x]
  spots[0][4].setData(GENERAL, true, BLACK, 'G', new generalMove());
  spots[0][3].setData(ADVISOR, true, BLACK, 'A', new advisorMove());
  spots[0][5].setData(ADVISOR, true, BLACK, 'A', new advisorMove());
  spots[0][2].setData(ELEPHANT, true, BLACK, 'E', new elephantMove());
  spots[0][6].setData(ELEPHANT, true, BLACK, 'E', new elephantMove());
  spots[0][1].setData(HORSE, true, BLACK, 'H', new horseMove());
  spots[0][7].setData(HORSE, true, BLACK, 'H', new horseMove());
  spots[0][0].setData(CHARIOT, true, BLACK, 'C', new chariotMove());
  spots[0][8].setData(CHARIOT, true, BLACK, 'C', new chariotMove());
  spots[2][1].setData(CANNON, true, BLACK, 'P', new powMove());
  spots[2][7].setData(CANNON, true, BLACK, 'P', new powMove());
  for(int x = 0; x < 9; x += 2)
  {
    spots[3][x].setData(SOLDIER, true, BLACK, 'S', new soldierMove());
  }
}

void updateChars(int status, ChessBoardSpot** spots)
{
  if(status == 1)
    defaultCoordinates(spots);

  // for(int a = 0; a < 16; a++)
  // {
  //   int pieceNum = blackCoors[a][2];
  //   int xC = blackCoors[a][0], yC = blackCoors[a][1];
  //
  //   boardChars[yC][xC] = pieceNum + 48;
  // }
}

void clearScreen()
{
  cout << "\033[2J\033[1;1H"; //Clears the terminal screen
}

void printBoard(int status, ChessBoardSpot** spots)
{

  int x, y;
  for(x = 0; x <= 9; x++)
  {
    //prints first
    for(y = 0; y <= 8; y++)
    {
      if(spots[x][y].getColor() == BLACK)
        cout << BLACK_C;
      else if(spots[x][y].getColor() == RED)
        cout << RED_C;
      cout << spots[x][y].getChar() << RESET;
      if(y != 8)
        cout << " -- ";
    }
    cout << endl;
    if(x == 4)
    {
      cout << left << setw(40) << "|" << "|" << endl;
      continue;
    }
    if(x != 9)
    {
      for(y = 0; y <= 8; y++)
      {
        cout << "|    ";
      }
      cout << endl;
    }
  }
  // for(int z = 0; z < 8; z++)
  // {
  //   if(spots[9][z].getColor() == BLACK)
  //     cout << BLACK_C;
  //   else if(spots[9][z].getColor() == RED)
  //       cout << RED_C;
  //   cout << spots[9][z].getChar() << RESET << " -- ";
  // }
  // if(spots[9][8].getColor() == BLACK)
  //   cout << BLACK_C;
  // else if(spots[9][8].getColor() == RED)
  //       cout << RED_C;
  // cout << spots[9][8].getChar() << RESET << endl;

  cout << endl;
}

#endif
