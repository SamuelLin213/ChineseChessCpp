#ifndef CHESS_DISPLAY_H
#define CHESS_DISPLAY_H

#include <iostream>
#include <vector>
// #include <set>
#include <iomanip>
#include <fstream>
using namespace std;

vector<vector<char>> boardChars(10, vector<char>(9, '*'));

void printDefault()
{
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
