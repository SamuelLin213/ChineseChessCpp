#ifndef GAME_H
#define GAME_H

#include "enums.h"
#include "chessDisplay.h"
#include "chessBoardSpot.h"
#include <unordered_map>
using namespace std;

bool saved = false;
bool redTurn = true;

void loadGame(ChessBoardSpot** spots);

void printIndex() {
  cout << "PIECE INDEX: " << endl;
  cout << setw(42) << setfill('-') << "" << endl;
  cout << setfill(' ') << left << setw(20) << "| G - General" << "| " << setw(19) << "A - Advisor" << "|" << endl;
  cout << setw(42) << setfill('-') << "" << endl;
  cout << setfill(' ') << setw(20) << "| E - Elephant" << "| " << setw(19) << "H - Horse" << "|" << endl;
  cout << setw(42) << setfill('-') << "" << endl;
  cout << setfill(' ') << setw(20) << "| C - Chariot" << "| " << setw(19) << "P - Cannon" << "|" << endl;
  cout << setw(42) << setfill('-') << "" << endl << setfill(' ');
  cout << setw(41) << "| S - Soldier" << "|" << endl;
  cout << setw(42) << setfill('-') << "" << endl << setfill(' ');
  cout << endl;
}

void initializeSpots(ChessBoardSpot** spots)
{
  for(int x = 0; x < BOARD_HEIGHT; x++)
  {
    spots[x] = new ChessBoardSpot[BOARD_WIDTH];

    for(int y = 0; y < BOARD_HEIGHT; y++)
    {
      spots[x][y] = ChessBoardSpot();
    }
  }
}

int playGame(int status)
{

  bool done = false; // when checkmate or end of game(quit/save)
  string pieceChoice;
  int coors[2]; // new coordinates
  int coorsO[2]; // original coordintes
  char confirm;

  ChessBoardSpot** spots = new ChessBoardSpot*[BOARD_HEIGHT];

  // don't need this manual pushing of names anymore -- use name inside spot
  // pieces.push_back("general");
  // pieces.push_back("advisor");
  // pieces.push_back("elephant");
  // pieces.push_back("horse");
  // pieces.push_back("chariot");
  // pieces.push_back("pow");
  // pieces.push_back("soldier");

  initializeSpots(spots);

  if(status == 1)
  {
    defaultCoordinates(spots);
  }
  else if(status == 2)
  {
    loadGame(spots);
  }

  // updateChars(status, spots);

  AGAIN:clearScreen();

  while(!done)
  {
    printIndex();

    printBoard(status, spots);

    cout << "Enter the coordinates of the piece to select, or enter -1 to quit: ";
    cin >> coorsO[0];

    if(coorsO[0] == -1)
    {
      return 3;
    }
    cin >> coorsO[1];

    if(coorsO[1] == -1)
    {
      return 3;
    }
    while(coorsO[0] < -1 || coorsO[0] > BOARD_WIDTH || coorsO[1] < -1 || coorsO[1] > BOARD_HEIGHT)
    {
      cout << "Invalid coordinates! Please try again.";
      cin.ignore();
      cin.get();

      cout << "Enter the coordinates of the piece to select, or enter -1 to quit: ";
      cin >> coorsO[0];

      if(coorsO[0] == 0)
      {
        return 3;
      }
      cin >> coorsO[1];

      if(coorsO[1] == 0)
      {
        return 3;
      }
    }

    //ChessBoardSpot temp = spots[0][0];
    ChessBoardSpot temp = spots[coorsO[1]][coorsO[0]];

    if(temp.getOccupied() == false)
    {
      cout << "Error: empty spot selected! Please choose a nonempty spot.";
      cin.ignore();
      cin.get();

      goto AGAIN;
    }
    if(redTurn && temp.getColor() != RED)
    {
      cout << "Error: wrong color selected! Please select a red piece.";
      cin.ignore();
      cin.get();

      goto AGAIN;
    }
    else if(!redTurn && temp.getColor() != BLACK)
    {
      cout << "Error: wrong color selected! Please select a black piece.";
      cin.ignore();
      cin.get();

      cin.clear();
      cin.ignore(10000,'\n');

      goto AGAIN;
    }

    cout << endl << "You chose " << temp.getPieceStr() << ". Confirm choice[y/n]: ";
    cin >> confirm;
    cout << "confirm choice";
    cin >> confirm;

    if(tolower(confirm) == 'y')
    {
      cout << "Enter the new coordinates(x y), with a space in between, or -1 to quit: ";
      cin >> coors[0];

      if(coors[0] == -1)
      {
        return 3;
      }

      cin >> coors[1];

      if(coors[1] == -1)
      {
        return 3;
      }

      while(coors[0] < -1 || coors[0] > BOARD_WIDTH || coors[1] < -1 || coors[1] > BOARD_HEIGHT)
      {
        cout << "Invalid coordinates! Please try again.";
        cin.ignore();
        cin.get();

        cout << "Enter the new coordinates(x y), with a space in between, or -1 to quit: ";
        cin >> coors[0];

        if(coors[0] == -1)
        {
          return 3;
        }

        cin >> coors[1];

        if(coors[1] == -1)
        {
          return 3;
        }

      }
      redTurn = !redTurn;
    }
    else{
      goto AGAIN;
    }

    //check validity of coordinates here(make sure they're within range of board)
  }
  return 1;
}

void loadGame(ChessBoardSpot** spots)
{
  vector<vector<int>> blackCoors(16, vector<int>(2, 0));
  vector<vector<int>> redCoors(16, vector<int>(2, 0));

  ifstream inData;
  inData.open("coordinates.txt");

  for(int x = 0; x < 16; x++)
  {
    for(int y = 0; y < 2; y++)
    {
      inData >> blackCoors[x][y];
    }
  }
  for(int x = 0; x < 16; x++)
  {
    for(int y = 0; y < 2; y++)
    {
      inData >> redCoors[x][y];
    }
  }

  // Creating black pieces
  spots[blackCoors[0][0]][blackCoors[0][1]].setData(GENERAL, true, BLACK, 'G', new generalMove());
  spots[blackCoors[1][0]][blackCoors[1][1]].setData(ADVISOR, true, BLACK, 'A', new advisorMove());
  spots[blackCoors[2][0]][blackCoors[2][1]].setData(ADVISOR, true, BLACK, 'A', new advisorMove());
  spots[blackCoors[3][0]][blackCoors[3][1]].setData(ELEPHANT, true, BLACK, 'E', new elephantMove());
  spots[blackCoors[4][0]][blackCoors[4][1]].setData(ELEPHANT, true, BLACK, 'E', new elephantMove());
  spots[blackCoors[5][0]][blackCoors[5][1]].setData(HORSE, true, BLACK, 'H', new horseMove());
  spots[blackCoors[6][0]][blackCoors[6][1]].setData(HORSE, true, BLACK, 'H', new horseMove());
  spots[blackCoors[7][0]][blackCoors[7][1]].setData(CHARIOT, true, BLACK, 'C', new chariotMove());
  spots[blackCoors[8][0]][blackCoors[8][1]].setData(CHARIOT, true, BLACK, 'C', new chariotMove());
  spots[blackCoors[9][0]][blackCoors[9][1]].setData(CANNON, true, BLACK, 'P', new powMove());
  spots[blackCoors[10][0]][blackCoors[10][1]].setData(CANNON, true, BLACK, 'P', new powMove());
  spots[blackCoors[11][0]][blackCoors[11][1]].setData(SOLDIER, true, BLACK, 'S', new soldierMove());
  spots[blackCoors[12][0]][blackCoors[12][1]].setData(SOLDIER, true, BLACK, 'S', new soldierMove());
  spots[blackCoors[13][0]][blackCoors[13][1]].setData(SOLDIER, true, BLACK, 'S', new soldierMove());
  spots[blackCoors[14][0]][blackCoors[14][1]].setData(SOLDIER, true, BLACK, 'S', new soldierMove());
  spots[blackCoors[15][0]][blackCoors[15][1]].setData(SOLDIER, true, BLACK, 'S', new soldierMove());

  // Creating red pieces
  spots[redCoors[0][0]][redCoors[0][1]].setData(GENERAL, true, RED, 'G', new generalMove());
  spots[redCoors[1][0]][redCoors[1][1]].setData(ADVISOR, true, RED, 'A', new advisorMove());
  spots[redCoors[2][0]][redCoors[2][1]].setData(ADVISOR, true, RED, 'A', new advisorMove());
  spots[redCoors[3][0]][redCoors[3][1]].setData(ELEPHANT, true, RED, 'E', new elephantMove());
  spots[redCoors[4][0]][redCoors[4][1]].setData(ELEPHANT, true, RED, 'E', new elephantMove());
  spots[redCoors[5][0]][redCoors[5][1]].setData(HORSE, true, RED, 'H', new horseMove());
  spots[redCoors[6][0]][redCoors[6][1]].setData(HORSE, true, RED, 'H', new horseMove());
  spots[redCoors[7][0]][redCoors[7][1]].setData(CHARIOT, true, RED, 'C', new chariotMove());
  spots[redCoors[8][0]][redCoors[8][1]].setData(CHARIOT, true, RED, 'C', new chariotMove());
  spots[redCoors[9][0]][redCoors[9][1]].setData(CANNON, true, RED, 'P', new powMove());
  spots[redCoors[10][0]][redCoors[10][1]].setData(CANNON, true, RED, 'P', new powMove());
  spots[redCoors[11][0]][redCoors[11][1]].setData(SOLDIER, true, RED, 'S', new soldierMove());
  spots[redCoors[12][0]][redCoors[12][1]].setData(SOLDIER, true, RED, 'S', new soldierMove());
  spots[redCoors[13][0]][redCoors[13][1]].setData(SOLDIER, true, RED, 'S', new soldierMove());
  spots[redCoors[14][0]][redCoors[14][1]].setData(SOLDIER, true, RED, 'S', new soldierMove());
  spots[redCoors[15][0]][redCoors[15][1]].setData(SOLDIER, true, RED, 'S', new soldierMove());

  inData.close();
}

void saveGame(ChessBoardSpot** spots)
{
  // ofstream outData;
  // outData.open("coordinates.txt");
  //
  // for(int x = 0; x < 16; x++)
  // {
  //   for(int y = 0; y < 2; y++)
  //   {
  //     outData << blackCoors[x][y] << " ";
  //   }
  //   outData << blackCoors[x][2] << endl;
  // }
}

#endif
