#ifndef CHESS_DISPLAY_H
#define CHESS_DISPLAY_H

#include <iostream>
#include <vector>
// #include <set>
#include <iomanip>
#include <fstream>
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
vector<vector<int>> redCoors(16, vector<int>(3, 0));
vector<vector<int>> blackCoors(16, vector<int>(3, 0));

void defaultCoordinates()
{
  // hard-code default coordinates for black pieces
  blackCoors[0] = {4, 0, 1};
  blackCoors[1] = {3, 0, 2};
  blackCoors[2] = {5, 0, 2};
  blackCoors[3] = {2, 0, 3};
  blackCoors[4] = {6, 0, 3};
  blackCoors[5] = {1, 0, 4};
  blackCoors[6] = {7, 0, 4};
  blackCoors[7] = {0, 0, 5};
  blackCoors[8] = {8, 0, 5};
  blackCoors[9] = {1, 2, 6};
  blackCoors[10] = {7, 2, 6};
  blackCoors[11] = {0, 3, 7};
  blackCoors[12] = {2, 3, 7};
  blackCoors[13] = {4, 3, 7};
  blackCoors[14] = {6, 3, 7};
  blackCoors[15] = {8, 3, 7};
}

void printDefault()
{
  defaultCoordinates();

  for(int a = 0; a < 16; a++)
  {
    int pieceNum = blackCoors[a][2];
    int xC = blackCoors[a][0], yC = blackCoors[a][1];

    boardChars[yC][xC] = pieceNum + 48;
  }

  int x, y;
  for(x = 0; x < 9; x++)
  {
    for(y = 0; y < 8; y++)
    {
      cout << boardChars[x][y] << " -- ";
    }
    cout << boardChars[x][y] << endl;
    if(x == 4)
    {
      cout << left << setw(40) << "|" << "|" << endl;
      continue;
    }
    for(y = 0; y < 8; y++)
    {
      cout << "|    ";
    }
    cout << "|   " << endl;
  }
  for(int z = 0; z < 8; z++)
  {
    cout << boardChars[9][z] << " -- ";
  }
  cout << boardChars[9][8] << endl;
}

void clearScreen()
{
  cout << "\033[2J\033[1;1H"; //Clears the terminal screen
}

void printBoard()
{
  // Will's board implementation
  printDefault();

  cout << endl;
}

#endif
