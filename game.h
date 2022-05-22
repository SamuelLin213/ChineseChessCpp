#ifndef GAME_H
#define GAME_H


chessBoardSpot myBoard[9][10]; 
#include "chessBoardSpot.h"
#include "enums.h"
#include "chessDisplay.h"
#include <unordered_map>
using namespace std;
bool saved = false;
void setUpBlackPieces();
void setUpRedPieces();
void setUpEmptyBlack();
void setUpEmptyRed();

void printIndex() {
  cout << "PIECE INDEX: " << endl;
  cout << setw(42) << setfill('-') << "" << endl;
  cout << setfill(' ') << left << setw(20) << "| G1 - General" << "| " << setw(19) << "A1/A2 - Advisor" << "|" << endl;
  cout << setw(42) << setfill('-') << "" << endl;
  cout << setfill(' ') << setw(20) << "| E1/E2 - Elephant" << "| " << setw(19) << "H1/H2 - Horse" << "|" << endl;
  cout << setw(42) << setfill('-') << "" << endl;
  cout << setfill(' ') << setw(20) << "| C1/C2 - Chariot" << "| " << setw(19) << "P1/P2 - Pow(Cannon)" << "|" << endl;
  cout << setw(42) << setfill('-') << "" << endl << setfill(' ');
  cout << setw(41) << "| S1/S2/S3/S4/S5 - Soldier" << "|" << endl;
  cout << setw(42) << setfill('-') << "" << endl << setfill(' ');
  cout << endl;
}

int playGame(int status)
{
  setUpBoard(); // we call this fucntion inorder to setup up our 2d array and get the game ready
  bool done = false; // when checkmate or end of game(quit/save)
  string pieceChoice;
  int coors[2];
  char confirm;

  pieces.push_back("general");
  pieces.push_back("advisor");
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

    if(pieceChoice == "0")
    {
      return 3;
    }
    while(pieceChoice < "0" || pieceChoice > to_string(NUM_PIECES))
    {
      cout << "Invalid piece! Please try again.";
      cin.ignore();
      cin.get();

      cout << "Enter a piece, or enter 0 to quit: ";
      cin >> pieceChoice;

      if(pieceChoice == "0")
      {
        return 3;
      }
    }

    // cout << endl << "You chose " << pieces[pieceChoice - 1] << ". Confirm choice[y/n]: ";
    // cin >> confirm;

    if(tolower(confirm) == 'y')
    {
      cout << "Enter the new coordinates(x y), with a space in between, or 0 to quit: ";
      cin >> coors[0];

      if(coors[0] == 0)
      {
        return 3;
      }

      cin >> coors[1];

      if(coors[1] == 0)
      {
        return 3;
      }

      while(coors[0] < 0 || coors[0] > BOARD_WIDTH || coors[1] < 0 || coors[1] > BOARD_HEIGHT)
      {
        cout << "Invalid piece! Please try again.";
        cin.ignore();
        cin.get();

        cout << "Enter the new coordinates(x y), with a space in between, or 0 to quit: ";
        cin >> coors[0];

        if(coors[0] == 0)
        {
          return 3;
        }

        cin >> coors[1];

        if(coors[1] == 0)
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

// 16 players above 
// 
// 16 players below 
void setUpBoard()
{
    myBoard[0][0] = chessBoardSpot(4, false, 1, 'C' ); // Chariot
    myBoard[0][1] = chessBoardSpot(3, false, 1, 'H' ); // Horse
    myBoard[0][2] = chessBoardSpot(2, false, 1, 'E' ); // Elepahnt
    myBoard[0][3] = chessBoardSpot(1, false, 1, 'A' ); // Advisor
    myBoard[0][4] = chessBoardSpot(0, false, 1, 'G' ); // General
    myBoard[0][5] = chessBoardSpot(1, false, 1, 'A' ); // Advisor
    myBoard[0][6] = chessBoardSpot(2, false, 1, 'E' ); // Elepahnt
    myBoard[0][7] = chessBoardSpot(3, false, 1, 'H' ); // Horse
    myBoard[0][8] = chessBoardSpot(4, false, 1, 'C' ); // Chariot
    myBoard[2][1] = chessBoardSpot(5, false, 1, 'C' ); // Pao
    myBoard[2][7] = chessBoardSpot(5, false, 1, 'C' ); // Pao
    myBoard[3][0] = chessBoardSpot(5, false, 1, 'S' ); // Soilder
    myBoard[3][2] = chessBoardSpot(5, false, 1, 'S' ); // Soilder
    myBoard[3][4] = chessBoardSpot(5, false, 1, 'S' ); // Soilder
    myBoard[3][6] = chessBoardSpot(5, false, 1, 'S' ); // Soilder
    myBoard[3][8] = chessBoardSpot(5, false, 1, 'S' ); // Soilder

}

void setUpRedPieces()
{
    myBoard[9][0] = chessBoardSpot(4, false, 0, 'C' ); // Chariot
    myBoard[9][1] = chessBoardSpot(3, false, 0, 'H' ); // Horse
    myBoard[9][2] = chessBoardSpot(2, false, 0, 'E' ); // Elepahnt
    myBoard[9][3] = chessBoardSpot(1, false, 0, 'A' ); // Advisor
    myBoard[9][4] = chessBoardSpot(0, false, 0, 'G' ); // General
    myBoard[9][5] = chessBoardSpot(1, false, 0, 'A' ); // Advisor
    myBoard[9][6] = chessBoardSpot(2, false, 0, 'E' ); // Elepahnt
    myBoard[9][7] = chessBoardSpot(3, false, 0, 'H' ); // Horse
    myBoard[9][8] = chessBoardSpot(4, false, 0, 'C' ); // Chariot
    myBoard[7][1] = chessBoardSpot(5, false, 0, 'C' ); // Pao
    myBoard[7][7] = chessBoardSpot(5, false, 0, 'C' ); // Pao
    myBoard[6][0] = chessBoardSpot(5, false, 0, 'S' ); // Soilder
    myBoard[6][2] = chessBoardSpot(5, false, 0, 'S' ); // Soilder
    myBoard[6][4] = chessBoardSpot(5, false, 0, 'S' ); // Soilder
    myBoard[6][6] = chessBoardSpot(5, false, 0, 'S' ); // Soilder
    myBoard[6][8] = chessBoardSpot(5, false, 0, 'S' ); // Soilder
}

void setUpEmptyBlack()
{
    for(int i = 0; i <= 8; i++)
        myBoard[1][i] = chessBoardSpot(7, true, 3, 'N' ); 
    
    myBoard[2][0] = chessBoardSpot(7, true, 3, 'N' ); 
    myBoard[2][8] = chessBoardSpot(7, true, 3, 'N' ); 
    
    for(int i = 2; i <= 6; i++)
        myBoard[2][i] = chessBoardSpot(7, true, 3, 'N' ); 

    myBoard[3][1] = chessBoardSpot(7, true, 3, 'N' ); 
    myBoard[3][3] = chessBoardSpot(7, true, 3, 'N' ); 
    myBoard[3][5] = chessBoardSpot(7, true, 3, 'N' ); 
    myBoard[3][7] = chessBoardSpot(7, true, 3, 'N' ); 

    for(int i = 0; i <= 8; i++)
        myBoard[4][i] = chessBoardSpot(7, true, 3, 'N' ); 
}

void setUpEmptyRed()
{
    for(int i = 0; i <= 8; i++)
      myBoard[5][i] = chessBoardSpot(7, true, 3, 'N' ); 

    myBoard[6][1] = chessBoardSpot(7, true, 3, 'N' ); 
    myBoard[6][3] = chessBoardSpot(7, true, 3, 'N' ); 
    myBoard[6][5] = chessBoardSpot(7, true, 3, 'N' ); 
    myBoard[6][7] = chessBoardSpot(7, true, 3, 'N' ); 

    myBoard[7][0] = chessBoardSpot(7, true, 3, 'N' ); 
    myBoard[7][8] = chessBoardSpot(7, true, 3, 'N' ); 

    for(int i = 0; i <= 8; i++)
        myBoard[8][i] = chessBoardSpot(7, true, 3, 'N' ); 
}
#endif
