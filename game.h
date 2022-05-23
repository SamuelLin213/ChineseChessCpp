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
  int targetLocation[2]; // new coordinates
  int chosenPiece[2]; // original coordintes
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

  while(!done)
  {
    AGAIN:clearScreen();

    printIndex();

    cout << "CURRENT TURN: ";
    if(redTurn)
      cout << "RED";
    else
      cout << "BLACK";
    cout << endl << endl;

    printBoard(status, spots);

    cout << "Enter the coordinates of the piece to select, or enter 0 to quit: ";
    cin >> chosenPiece[0];

    if(chosenPiece[0] == 0)
    {
      return 3;
    }
    cin >> chosenPiece[1];

    if(chosenPiece[1] == 0)
    {
      return 3;
    }
    if(chosenPiece[0] < 0 || chosenPiece[0] > BOARD_WIDTH || chosenPiece[1] < 0 || chosenPiece[1] > BOARD_HEIGHT)
    {
      cout << "Invalid coordinates! Please try again.";
      cin.ignore();
      cin.get();

      goto AGAIN;
    }
    chosenPiece[0] -= 1;
    chosenPiece[1] -= 1;

    //ChessBoardSpot temp = spots[0][0];
    ChessBoardSpot temp = spots[chosenPiece[1]][chosenPiece[0]];

    if(temp.getPiece() == EMPTY)
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

      goto AGAIN;
    }

    cout << endl << "You chose " << temp.getPieceStr() << ". Confirm choice[y/n]: ";
    cin >> confirm;

    if(tolower(confirm) == 'y')
    {
      NEWCOOR:cout << "Enter the new coordinates(x y), with a space in between, or 0 to quit: ";
      cin >> targetLocation[0];

      if(targetLocation[0] == 0)
      {
        return 3;
      }

      cin >> targetLocation[1];

      if(targetLocation[1] == 0)
      {
        return 3;
      }

      if(targetLocation[0] < 0 || targetLocation[0] > BOARD_WIDTH || targetLocation[1] < 0 || targetLocation[1] > BOARD_HEIGHT)
      {
        cout << "Invalid coordinates! Please try again.";
        cin.ignore();
        cin.get();

        cout << "Enter the new coordinates(x y), with a space in between, or 0 to quit: ";
        cin >> targetLocation[0];

        if(targetLocation[0] == 0)
        {
          return 3;
        }

        cin >> targetLocation[1];

        if(targetLocation[1] == 0)
        {
          return 3;
        }
      }
      targetLocation[0] -= 1;
      targetLocation[1] -= 1;

      temp = spots[targetLocation[1]][targetLocation[0]];

      if(redTurn && temp.getColor() == RED)
      {
        cout << "Error: wrong target color! Please select a black piece to capture.";
        cin.ignore();
        cin.get();

        goto NEWCOOR;
      }
      else if(!redTurn && temp.getColor() == BLACK)
      {
        cout << "Error: wrong target color! Please select a red piece to capture.";
        cin.ignore();
        cin.get();

        goto NEWCOOR;
      }

      //coorsO - original coordinates, coors - new coordinates
      spots[chosenPiece[1]][chosenPiece[0]].getMove()->setCoors(chosenPiece[0], chosenPiece[1], targetLocation[0], targetLocation[1]);
      if(spots[chosenPiece[1]][chosenPiece[0]].getMove()->move(spotOccupied, spots[chosenPiece[1]][chosenPiece[0]].getColor(), kingCoor))
      {
        spots[targetLocation[1]][targetLocation[0]] = spots[chosenPiece[1]][chosenPiece[0]];
        spots[chosenPiece[1]][chosenPiece[0]].clear();
      }
      else{
        cout << "Invalid move! Please try again.";
        cin.ignore();
        cin.get();

        goto AGAIN;
      }

      // Check target spot is empty

      redTurn = !redTurn; // inverses so that it's the other player's turn
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
      inData >> blacktargetLocation[x][y];
    }
  }
  for(int x = 0; x < 16; x++)
  {
    for(int y = 0; y < 2; y++)
    {
      inData >> redtargetLocation[x][y];
    }
  }

  // Creating black pieces
  spots[blacktargetLocation[0][0]][blacktargetLocation[0][1]].setData(GENERAL, BLACK, 'G', new generalMove());
  spots[blacktargetLocation[1][0]][blacktargetLocation[1][1]].setData(ADVISOR, BLACK, 'A', new advisorMove());
  spots[blacktargetLocation[2][0]][blacktargetLocation[2][1]].setData(ADVISOR, BLACK, 'A', new advisorMove());
  spots[blacktargetLocation[3][0]][blacktargetLocation[3][1]].setData(ELEPHANT, BLACK, 'E', new elephantMove());
  spots[blacktargetLocation[4][0]][blacktargetLocation[4][1]].setData(ELEPHANT, BLACK, 'E', new elephantMove());
  spots[blacktargetLocation[5][0]][blacktargetLocation[5][1]].setData(HORSE,  BLACK, 'H', new horseMove());
  spots[blacktargetLocation[6][0]][blacktargetLocation[6][1]].setData(HORSE,  BLACK, 'H', new horseMove());
  spots[blacktargetLocation[7][0]][blacktargetLocation[7][1]].setData(CHARIOT,  BLACK, 'C', new chariotMove());
  spots[blacktargetLocation[8][0]][blacktargetLocation[8][1]].setData(CHARIOT,  BLACK, 'C', new chariotMove());
  spots[blacktargetLocation[9][0]][blacktargetLocation[9][1]].setData(CANNON,  BLACK, 'P', new powMove());
  spots[blacktargetLocation[10][0]][blacktargetLocation[10][1]].setData(CANNON,  BLACK, 'P', new powMove());
  spots[blacktargetLocation[11][0]][blacktargetLocation[11][1]].setData(SOLDIER, BLACK, 'S', new soldierMove());
  spots[blacktargetLocation[12][0]][blacktargetLocation[12][1]].setData(SOLDIER, BLACK, 'S', new soldierMove());
  spots[blacktargetLocation[13][0]][blacktargetLocation[13][1]].setData(SOLDIER, BLACK, 'S', new soldierMove());
  spots[blacktargetLocation[14][0]][blacktargetLocation[14][1]].setData(SOLDIER, BLACK, 'S', new soldierMove());
  spots[blacktargetLocation[15][0]][blacktargetLocation[15][1]].setData(SOLDIER, BLACK, 'S', new soldierMove());
  kingCoor[0] = blacktargetLocation[0][1];
  kingCoor[1] = blacktargetLocation[0][0];

  // Creating red pieces
  spots[redtargetLocation[0][0]][redtargetLocation[0][1]].setData(GENERAL,  RED, 'G', new generalMove());
  spots[redtargetLocation[1][0]][redtargetLocation[1][1]].setData(ADVISOR,  RED, 'A', new advisorMove());
  spots[redtargetLocation[2][0]][redtargetLocation[2][1]].setData(ADVISOR,  RED, 'A', new advisorMove());
  spots[redtargetLocation[3][0]][redtargetLocation[3][1]].setData(ELEPHANT,  RED, 'E', new elephantMove());
  spots[redtargetLocation[4][0]][redtargetLocation[4][1]].setData(ELEPHANT,  RED, 'E', new elephantMove());
  spots[redtargetLocation[5][0]][redtargetLocation[5][1]].setData(HORSE,  RED, 'H', new horseMove());
  spots[redtargetLocation[6][0]][redtargetLocation[6][1]].setData(HORSE,  RED, 'H', new horseMove());
  spots[redtargetLocation[7][0]][redtargetLocation[7][1]].setData(CHARIOT,  RED, 'C', new chariotMove());
  spots[redtargetLocation[8][0]][redtargetLocation[8][1]].setData(CHARIOT,  RED, 'C', new chariotMove());
  spots[redtargetLocation[9][0]][redtargetLocation[9][1]].setData(CANNON,  RED, 'P', new powMove());
  spots[redtargetLocation[10][0]][redtargetLocation[10][1]].setData(CANNON,  RED, 'P', new powMove());
  spots[redtargetLocation[11][0]][redtargetLocation[11][1]].setData(SOLDIER,  RED, 'S', new soldierMove());
  spots[redtargetLocation[12][0]][redtargetLocation[12][1]].setData(SOLDIER,  RED, 'S', new soldierMove());
  spots[redtargetLocation[13][0]][redtargetLocation[13][1]].setData(SOLDIER,  RED, 'S', new soldierMove());
  spots[redtargetLocation[14][0]][redtargetLocation[14][1]].setData(SOLDIER,  RED, 'S', new soldierMove());
  spots[redtargetLocation[15][0]][redtargetLocation[15][1]].setData(SOLDIER,  RED, 'S', new soldierMove());
  kingCoor[0] = redtargetLocation[0][1];
  kingCoor[1] = redtargetLocation[0][0];

  for(int x = 0; x < 10; x++)
  {
    for(int y = 0; y < 9; y++)
    {
      if(spots[x][y].getPiece() == EMPTY)
        spotOccupied[x][y] = false;
      else
        spotOccupied[x][y] = true;
    }
  }

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
  //     outData << blacktargetLocation[x][y] << " ";
  //   }
  //   outData << blacktargetLocation[x][2] << endl;
  // }
}

#endif
