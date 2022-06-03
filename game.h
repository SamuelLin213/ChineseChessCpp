#ifndef GAME_H
#define GAME_H

#include "enums.h"
#include "chessDisplay.h"
#include <limits>
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

void deleteSpots(ChessBoardSpot** spots)
{
  for(int x = 0; x < BOARD_HEIGHT; x++)
  {
    // for(int y = 0; y < BOARD_HEIGHT; y++)
    // {
    //   delete spots[x][y];
    // }
    delete [] spots[x];
  }
  delete [] spots;
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
    ChessBoardSpot temp(spots[chosenPiece[1]][chosenPiece[0]]);

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

        goto AGAIN;
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
        if(spots[chosenPiece[1]][chosenPiece[0]].getPiece() == GENERAL)
        {
          if(spots[chosenPiece[1]][chosenPiece[0]].getColor() == BLACK)
          {
            kingCoor[0] = targetLocation[0];
            kingCoor[1] = targetLocation[1];
            cout << "New general coor: " << kingCoor[0] << " " << kingCoor[1] << endl;
            cin.ignore();
            cin.get();
          }
          else if(spots[chosenPiece[1]][chosenPiece[0]].getColor() == RED)
          {
            kingCoor[2] = targetLocation[0];
            kingCoor[3] = targetLocation[1];
            cout << "New general coor: " << kingCoor[2] << " " << kingCoor[3] << endl;
            cin.ignore();
            cin.get();
          }
        }
        if(spots[targetLocation[1]][targetLocation[0]].getPiece() == GENERAL)
        {
          done = true;
        }

        //ChessBoardSpot tempSpot(spots[chosenPiece[1]][chosenPiece[0]]);
        //spots[targetLocation[1]][targetLocation[0]].clear();
        spots[targetLocation[1]][targetLocation[0]].cpy(spots[chosenPiece[1]][chosenPiece[0]]);
        spots[chosenPiece[1]][chosenPiece[0]].clear();
        spotOccupied[targetLocation[1]][targetLocation[0]] = true;
        spotOccupied[chosenPiece[1]][chosenPiece[0]] = false;

        if(spots[targetLocation[1]][targetLocation[0]].getMove() == nullptr)
        {
          cout << "Target has null pointer!" << endl;
          cin.ignore();
          cin.get();
        }
        else {
          switch(spots[targetLocation[1]][targetLocation[0]].getPiece())
          {
            case GENERAL:
            {
              cout << "Target has gen pointer!" << endl;
              cin.ignore();
              cin.get();
              break;
            }
            case ADVISOR:
            {
              cout << "Target has adv pointer!" << endl;
              cin.ignore();
              cin.get();
              break;
            }
            case ELEPHANT:
            {
              cout << "Target has elephant pointer!" << endl;
              cin.ignore();
              cin.get();
              break;
            }
            case HORSE:
            {
              cout << "Target has horse pointer!" << endl;
              cin.ignore();
              cin.get();
              break;
            }
            case CHARIOT:
            {
              cout << "Target has chariot pointer!" << endl;
              cin.ignore();
              cin.get();
              break;
            }
            case CANNON:
            {
              cout << "Target has cannon pointer!" << endl;
              cin.ignore();
              cin.get();
              break;
            }
            case SOLDIER:
            {
              cout << "Target has soldier pointer!" << endl;
              cin.ignore();
              cin.get();
              break;
            }
            default:
            {
              cout << "???" << endl;
              cin.ignore();
              cin.get();
              break;
            }
          }
        }
      }
      else{
        cout << "Invalid move! Please try again.";
        cin.ignore();
        cin.get();

        goto AGAIN;
      }
      if(done)
      {
        string winTeam = (redTurn) ? "Team red" : "Team black";
        cout << endl << YELLOW << "Checkmate! " << winTeam << " won!" << endl;
        cin.ignore();
        cin.get();
        cout << RESET;
      }
      // Check target spot is empty
      redTurn = !redTurn; // inverses so that it's the other player's turn
    }
    else{
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      goto AGAIN;
    }
  }

  deleteSpots(spots);

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
  spots[blackCoors[0][0]][blackCoors[0][1]].setData(GENERAL, BLACK, 'G', new generalMove());
  spots[blackCoors[1][0]][blackCoors[1][1]].setData(ADVISOR, BLACK, 'A', new advisorMove());
  spots[blackCoors[2][0]][blackCoors[2][1]].setData(ADVISOR, BLACK, 'A', new advisorMove());
  spots[blackCoors[3][0]][blackCoors[3][1]].setData(ELEPHANT, BLACK, 'E', new elephantMove());
  spots[blackCoors[4][0]][blackCoors[4][1]].setData(ELEPHANT, BLACK, 'E', new elephantMove());
  spots[blackCoors[5][0]][blackCoors[5][1]].setData(HORSE,  BLACK, 'H', new horseMove());
  spots[blackCoors[6][0]][blackCoors[6][1]].setData(HORSE,  BLACK, 'H', new horseMove());
  spots[blackCoors[7][0]][blackCoors[7][1]].setData(CHARIOT,  BLACK, 'C', new chariotMove());
  spots[blackCoors[8][0]][blackCoors[8][1]].setData(CHARIOT,  BLACK, 'C', new chariotMove());
  spots[blackCoors[9][0]][blackCoors[9][1]].setData(CANNON,  BLACK, 'P', new powMove());
  spots[blackCoors[10][0]][blackCoors[10][1]].setData(CANNON,  BLACK, 'P', new powMove());
  spots[blackCoors[11][0]][blackCoors[11][1]].setData(SOLDIER, BLACK, 'S', new soldierMove());
  spots[blackCoors[12][0]][blackCoors[12][1]].setData(SOLDIER, BLACK, 'S', new soldierMove());
  spots[blackCoors[13][0]][blackCoors[13][1]].setData(SOLDIER, BLACK, 'S', new soldierMove());
  spots[blackCoors[14][0]][blackCoors[14][1]].setData(SOLDIER, BLACK, 'S', new soldierMove());
  spots[blackCoors[15][0]][blackCoors[15][1]].setData(SOLDIER, BLACK, 'S', new soldierMove());
  kingCoor[0] = blackCoors[0][1];
  kingCoor[1] = blackCoors[0][0];

  // Creating red pieces
  spots[redCoors[0][0]][redCoors[0][1]].setData(GENERAL,  RED, 'G', new generalMove());
  spots[redCoors[1][0]][redCoors[1][1]].setData(ADVISOR,  RED, 'A', new advisorMove());
  spots[redCoors[2][0]][redCoors[2][1]].setData(ADVISOR,  RED, 'A', new advisorMove());
  spots[redCoors[3][0]][redCoors[3][1]].setData(ELEPHANT,  RED, 'E', new elephantMove());
  spots[redCoors[4][0]][redCoors[4][1]].setData(ELEPHANT,  RED, 'E', new elephantMove());
  spots[redCoors[5][0]][redCoors[5][1]].setData(HORSE,  RED, 'H', new horseMove());
  spots[redCoors[6][0]][redCoors[6][1]].setData(HORSE,  RED, 'H', new horseMove());
  spots[redCoors[7][0]][redCoors[7][1]].setData(CHARIOT,  RED, 'C', new chariotMove());
  spots[redCoors[8][0]][redCoors[8][1]].setData(CHARIOT,  RED, 'C', new chariotMove());
  spots[redCoors[9][0]][redCoors[9][1]].setData(CANNON,  RED, 'P', new powMove());
  spots[redCoors[10][0]][redCoors[10][1]].setData(CANNON,  RED, 'P', new powMove());
  spots[redCoors[11][0]][redCoors[11][1]].setData(SOLDIER,  RED, 'S', new soldierMove());
  spots[redCoors[12][0]][redCoors[12][1]].setData(SOLDIER,  RED, 'S', new soldierMove());
  spots[redCoors[13][0]][redCoors[13][1]].setData(SOLDIER,  RED, 'S', new soldierMove());
  spots[redCoors[14][0]][redCoors[14][1]].setData(SOLDIER,  RED, 'S', new soldierMove());
  spots[redCoors[15][0]][redCoors[15][1]].setData(SOLDIER,  RED, 'S', new soldierMove());
  kingCoor[0] = redCoors[0][1];
  kingCoor[1] = redCoors[0][0];

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
  //     outData << blackCoors[x][y] << " ";
  //   }
  //   outData << blackCoors[x][2] << endl;
  // }
}

#endif
