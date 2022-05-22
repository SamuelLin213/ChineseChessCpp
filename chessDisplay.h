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
  for(int x = 0; x < 9; x++)
  {
    for(int y = 0; y < 8; y++)
    {
      spots[x][y].clear();
    }
  }
}

void defaultCoordinates(ChessBoardSpot** spots)
{
  // Note that the x and y coordinates are swapped for the spots array; spots[y][x]

  // Black pieces
  spots[0][4].setData(GENERAL, BLACK, 'G', new generalMove());
  spots[0][3].setData(ADVISOR, BLACK, 'A', new advisorMove());
  spots[0][5].setData(ADVISOR, BLACK, 'A', new advisorMove());
  spots[0][2].setData(ELEPHANT, BLACK, 'E', new elephantMove());
  spots[0][6].setData(ELEPHANT, BLACK, 'E', new elephantMove());
  spots[0][1].setData(HORSE, BLACK, 'H', new horseMove());
  spots[0][7].setData(HORSE, BLACK, 'H', new horseMove());
  spots[0][0].setData(CHARIOT, BLACK, 'C', new chariotMove());
  spots[0][8].setData(CHARIOT, BLACK, 'C', new chariotMove());
  spots[2][1].setData(CANNON, BLACK, 'P', new powMove());
  spots[2][7].setData(CANNON, BLACK, 'P', new powMove());
  for(int x = 0; x < 9; x += 2)
  {
    spots[3][x].setData(SOLDIER, BLACK, 'S', new soldierMove());
  }

  // Red pieces
  spots[9][4].setData(GENERAL, RED, 'G', new generalMove());
  spots[9][3].setData(ADVISOR, RED, 'A', new advisorMove());
  spots[9][5].setData(ADVISOR, RED, 'A', new advisorMove());
  spots[9][2].setData(ELEPHANT, RED, 'E', new elephantMove());
  spots[9][6].setData(ELEPHANT, RED, 'E', new elephantMove());
  spots[9][1].setData(HORSE, RED, 'H', new horseMove());
  spots[9][7].setData(HORSE, RED, 'H', new horseMove());
  spots[9][0].setData(CHARIOT, RED, 'C', new chariotMove());
  spots[9][8].setData(CHARIOT, RED, 'C', new chariotMove());
  spots[7][1].setData(CANNON, RED, 'P', new powMove());
  spots[7][7].setData(CANNON, RED, 'P', new powMove());
  for(int x = 0; x < 9; x += 2)
  {
    spots[6][x].setData(SOLDIER, RED, 'S', new soldierMove());
  }
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
