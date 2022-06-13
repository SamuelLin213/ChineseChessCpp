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
void saveGame(ChessBoardSpot** spots);

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

    for(int y = 0; y < BOARD_WIDTH; y++)
    {
      spots[x][y] = ChessBoardSpot();
    }
  }
}

void deleteSpots(ChessBoardSpot** spots)
{
  for(int x = 0; x < BOARD_HEIGHT; x++)
  {
    if(spots[x] != nullptr)
        delete [] spots[x];
  }
  delete [] spots;
}

int playGame(int status)
{
  bool check = false;
  bool done = false; // when checkmate or end of game(quit/save)
  string pieceChoice;
  int targetLocation[2]; // new coordinates
  int chosenPiece[2]; // original coordintes
  char confirm;

  ChessBoardSpot** spots = new ChessBoardSpot*[BOARD_HEIGHT];

  initializeSpots(spots);

  if(status == 1)
  {
    defaultCoordinates(spots);
  }
  else if(status == 2)
  {
    loadGame(spots);
  }

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

    if(check)
    {
        redTurn = !redTurn;
        string winTeam = (redTurn) ? "Red team" : "Black team";
        cout << endl << YELLOW << "Checkmate! " << winTeam << " won!" << endl;
        cin.ignore();
        cin.get();
        cout << RESET;

        done = true;
        break;
    }

    cout << "Enter the coordinates of the piece to select, or enter 0 to quit: ";
    cin >> chosenPiece[0];

    if(chosenPiece[0] == 0)
    {
      saveGame(spots);
      deleteSpots(spots);
      return 3;
    }
    cin >> chosenPiece[1];

    if(chosenPiece[1] == 0)
    {
      saveGame(spots);
      deleteSpots(spots);
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
        saveGame(spots);
        deleteSpots(spots);
        return 3;
      }

      cin >> targetLocation[1];

      if(targetLocation[1] == 0)
      {
        saveGame(spots);
        deleteSpots(spots);
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

      temp.clear();

      temp.cpy(spots[targetLocation[1]][targetLocation[0]]);

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
      temp.clear();

      spots[chosenPiece[1]][chosenPiece[0]].getMove()->setCoors(chosenPiece[0], chosenPiece[1], targetLocation[0], targetLocation[1]);
      if(spots[chosenPiece[1]][chosenPiece[0]].getMove()->move(spotOccupied, spots[chosenPiece[1]][chosenPiece[0]].getColor(), kingCoor))
      {
        if(spots[chosenPiece[1]][chosenPiece[0]].getPiece() == GENERAL)
        {
          if(spots[chosenPiece[1]][chosenPiece[0]].getColor() == BLACK)
          {
            kingCoor[0] = targetLocation[0];
            kingCoor[1] = targetLocation[1];
          }
          else if(spots[chosenPiece[1]][chosenPiece[0]].getColor() == RED)
          {
            kingCoor[2] = targetLocation[0];
            kingCoor[3] = targetLocation[1];
          }
        }
        if(spots[targetLocation[1]][targetLocation[0]].getPiece() == GENERAL)
        {
          check = true;
        }

        spots[targetLocation[1]][targetLocation[0]].cpy(spots[chosenPiece[1]][chosenPiece[0]]);
        spots[chosenPiece[1]][chosenPiece[0]].clear();
        spotOccupied[targetLocation[1]][targetLocation[0]] = true;
        spotOccupied[chosenPiece[1]][chosenPiece[0]] = false;

      }
      else{
        cout << "Invalid move! Please try again.";
        cin.ignore();
        cin.get();

        goto AGAIN;
      }
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
  char turn;

  vector<vector<int>> blackCoors(16, vector<int>(2, 0));
  vector<vector<int>> redCoors(16, vector<int>(2, 0));

  ifstream inData;
  inData.open("coordinates.txt");

  inData >> turn;
  if(tolower(turn) == 'r')
  {
    redTurn = true;
  }
  else{
    redTurn = false;
  }

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
  if(blackCoors[0][0] != -1 && blackCoors[0][1] != -1)
    spots[blackCoors[0][0]][blackCoors[0][1]].setData(GENERAL, BLACK, 'G', new generalMove());
  if(blackCoors[1][0] != -1 && blackCoors[1][1] != -1)
    spots[blackCoors[1][0]][blackCoors[1][1]].setData(ADVISOR, BLACK, 'A', new advisorMove());
  if(blackCoors[2][0] != -1 && blackCoors[2][1] != -1)
    spots[blackCoors[2][0]][blackCoors[2][1]].setData(ADVISOR, BLACK, 'A', new advisorMove());
  if(blackCoors[3][0] != -1 && blackCoors[3][1] != -1)
    spots[blackCoors[3][0]][blackCoors[3][1]].setData(ELEPHANT, BLACK, 'E', new elephantMove());
  if(blackCoors[4][0] != -1 && blackCoors[4][1] != -1)
    spots[blackCoors[4][0]][blackCoors[4][1]].setData(ELEPHANT, BLACK, 'E', new elephantMove());
  if(blackCoors[5][0] != -1 && blackCoors[5][1] != -1)
    spots[blackCoors[5][0]][blackCoors[5][1]].setData(HORSE,  BLACK, 'H', new horseMove());
  if(blackCoors[6][0] != -1 && blackCoors[6][1] != -1)
    spots[blackCoors[6][0]][blackCoors[6][1]].setData(HORSE,  BLACK, 'H', new horseMove());
  if(blackCoors[7][0] != -1 && blackCoors[7][1] != -1)
    spots[blackCoors[7][0]][blackCoors[7][1]].setData(CHARIOT,  BLACK, 'C', new chariotMove());
  if(blackCoors[8][0] != -1 && blackCoors[8][1] != -1)
    spots[blackCoors[8][0]][blackCoors[8][1]].setData(CHARIOT,  BLACK, 'C', new chariotMove());
  if(blackCoors[9][0] != -1 && blackCoors[9][1] != -1)
    spots[blackCoors[9][0]][blackCoors[9][1]].setData(CANNON,  BLACK, 'P', new powMove());
  if(blackCoors[10][0] != -1 && blackCoors[10][1] != -1)
    spots[blackCoors[10][0]][blackCoors[10][1]].setData(CANNON,  BLACK, 'P', new powMove());
  if(blackCoors[11][0] != -1 && blackCoors[11][1] != -1)
    spots[blackCoors[11][0]][blackCoors[11][1]].setData(SOLDIER, BLACK, 'S', new soldierMove());
  if(blackCoors[12][0] != -1 && blackCoors[12][1] != -1)
    spots[blackCoors[12][0]][blackCoors[12][1]].setData(SOLDIER, BLACK, 'S', new soldierMove());
  if(blackCoors[13][0] != -1 && blackCoors[13][1] != -1)
    spots[blackCoors[13][0]][blackCoors[13][1]].setData(SOLDIER, BLACK, 'S', new soldierMove());
  if(blackCoors[14][0] != -1 && blackCoors[14][1] != -1)
    spots[blackCoors[14][0]][blackCoors[14][1]].setData(SOLDIER, BLACK, 'S', new soldierMove());
  if(blackCoors[15][0] != -1 && blackCoors[15][1] != -1)
    spots[blackCoors[15][0]][blackCoors[15][1]].setData(SOLDIER, BLACK, 'S', new soldierMove());
  kingCoor[0] = blackCoors[0][1];
  kingCoor[1] = blackCoors[0][0];

  // Creating red pieces
  if(redCoors[0][0] != -1 && redCoors[0][1] != -1)
    spots[redCoors[0][0]][redCoors[0][1]].setData(GENERAL,  RED, 'G', new generalMove());
  if(redCoors[1][0] != -1 && redCoors[1][1] != -1)
    spots[redCoors[1][0]][redCoors[1][1]].setData(ADVISOR,  RED, 'A', new advisorMove());
  if(redCoors[2][0] != -1 && redCoors[2][1] != -1)
    spots[redCoors[2][0]][redCoors[2][1]].setData(ADVISOR,  RED, 'A', new advisorMove());
  if(redCoors[3][0] != -1 && redCoors[3][1] != -1)
    spots[redCoors[3][0]][redCoors[3][1]].setData(ELEPHANT,  RED, 'E', new elephantMove());
  if(redCoors[4][0] != -1 && redCoors[4][1] != -1)
    spots[redCoors[4][0]][redCoors[4][1]].setData(ELEPHANT,  RED, 'E', new elephantMove());
  if(redCoors[5][0] != -1 && redCoors[5][1] != -1)
    spots[redCoors[5][0]][redCoors[5][1]].setData(HORSE,  RED, 'H', new horseMove());
  if(redCoors[6][0] != -1 && redCoors[6][1] != -1)
  spots[redCoors[6][0]][redCoors[6][1]].setData(HORSE,  RED, 'H', new horseMove());
  if(redCoors[7][0] != -1 && redCoors[7][1] != -1)
  spots[redCoors[7][0]][redCoors[7][1]].setData(CHARIOT,  RED, 'C', new chariotMove());
  if(redCoors[8][0] != -1 && redCoors[8][1] != -1)
  spots[redCoors[8][0]][redCoors[8][1]].setData(CHARIOT,  RED, 'C', new chariotMove());
  if(redCoors[9][0] != -1 && redCoors[9][1] != -1)
  spots[redCoors[9][0]][redCoors[9][1]].setData(CANNON,  RED, 'P', new powMove());
  if(redCoors[10][0] != -1 && redCoors[10][1] != -1)
  spots[redCoors[10][0]][redCoors[10][1]].setData(CANNON,  RED, 'P', new powMove());
  if(redCoors[11][0] != -1 && redCoors[11][1] != -1)
  spots[redCoors[11][0]][redCoors[11][1]].setData(SOLDIER,  RED, 'S', new soldierMove());
  if(redCoors[12][0] != -1 && redCoors[12][1] != -1)
  spots[redCoors[12][0]][redCoors[12][1]].setData(SOLDIER,  RED, 'S', new soldierMove());
  if(redCoors[13][0] != -1 && redCoors[13][1] != -1)
  spots[redCoors[13][0]][redCoors[13][1]].setData(SOLDIER,  RED, 'S', new soldierMove());
  if(redCoors[14][0] != -1 && redCoors[14][1] != -1)
  spots[redCoors[14][0]][redCoors[14][1]].setData(SOLDIER,  RED, 'S', new soldierMove());
  if(redCoors[15][0] != -1 && redCoors[15][1] != -1)
  spots[redCoors[15][0]][redCoors[15][1]].setData(SOLDIER,  RED, 'S', new soldierMove());
  kingCoor[0] = redCoors[0][1];
  kingCoor[1] = redCoors[0][0];

  for(int x = 0; x < BOARD_HEIGHT; x++)
  {
    for(int y = 0; y < BOARD_WIDTH; y++)
    {
      if(spots[x][y].getPiece() == EMPTY)
        spotOccupied[x][y] = false;
      else
        spotOccupied[x][y] = true;
    }
  }

  inData.close();
}

bool findPiece(ChessBoardSpot** spots, colorEnum color, pieceTypeEnum piece, vector<int> &coors)
{
  coors.clear();
  for(int y = 0; y < BOARD_HEIGHT; y++)
  {
    for(int x = 0; x < BOARD_WIDTH; x++)
    {
      if(spots[y][x].getColor() == color && spots[y][x].getPiece() == piece)
      {
        coors.push_back(y);
        coors.push_back(x);
      }
    }
  }
  if(coors.size() > 0)
    return true;
  return false;
}

void saveGame(ChessBoardSpot** spots)
{
  char saveChoice = 'n';

  cin.clear();
  cin.ignore();

  cout << endl << "Quitting the game. Save current game? <y/n>: ";
  cin.get(saveChoice);

  if(tolower(saveChoice) == 'n')
  {
    return;
  }

  ofstream outData;
  outData.open("coordinates.txt");

  if(redTurn)
  {
    outData << "r" << endl;
  }
  else{
    outData << "b" << endl;
  }

  vector<int> coordinate;
  //Black pieces
  if(findPiece(spots, BLACK, GENERAL, coordinate))
  {
    outData << coordinate[0] << " " << coordinate[1] << endl;
  }
  else
  {
    outData << -1 << " " << -1 << endl;
  }
  if(findPiece(spots, BLACK, ADVISOR, coordinate))
  {
    outData << coordinate[0] << " " << coordinate[1] << endl;
    if(coordinate.size() == 2)
      outData << -1 << " " << -1 << endl;
    else
      outData << coordinate[2] << " " << coordinate[3] << endl;
  }
  else
  {
    outData << -1 << " " << -1 << endl;
    outData << -1 << " " << -1 << endl;
  }
  if(findPiece(spots, BLACK, ELEPHANT, coordinate))
  {
    outData << coordinate[0] << " " << coordinate[1] << endl;
    if(coordinate.size() == 2)
      outData << -1 << " " << -1 << endl;
    else
      outData << coordinate[2] << " " << coordinate[3] << endl;
  }
  else
  {
    outData << -1 << " " << -1 << endl;
    outData << -1 << " " << -1 << endl;
  }
  if(findPiece(spots, BLACK, HORSE, coordinate))
  {
    outData << coordinate[0] << " " << coordinate[1] << endl;
    if(coordinate.size() == 2)
      outData << -1 << " " << -1 << endl;
    else
      outData << coordinate[2] << " " << coordinate[3] << endl;
  }
  else
  {
    outData << -1 << " " << -1 << endl;
    outData << -1 << " " << -1 << endl;
  }
  if(findPiece(spots, BLACK, CHARIOT, coordinate))
  {
    outData << coordinate[0] << " " << coordinate[1] << endl;
    if(coordinate.size() == 2)
      outData << -1 << " " << -1 << endl;
    else
      outData << coordinate[2] << " " << coordinate[3] << endl;
  }
  else
  {
    outData << -1 << " " << -1 << endl;
    outData << -1 << " " << -1 << endl;
  }
  if(findPiece(spots, BLACK, CANNON, coordinate))
  {
    outData << coordinate[0] << " " << coordinate[1] << endl;
    if(coordinate.size() == 2)
      outData << -1 << " " << -1 << endl;
    else
      outData << coordinate[2] << " " << coordinate[3] << endl;
  }
  else
  {
    outData << -1 << " " << -1 << endl;
    outData << -1 << " " << -1 << endl;
  }
  if(findPiece(spots, BLACK, SOLDIER, coordinate))
  {
    for(int x = 0; x < coordinate.size(); x++)
    {
      outData << coordinate[x] << " ";
      if(x % 2 == 1)
        outData << endl;
    }
    for(int y = coordinate.size(); y < 10; y++)
    {
      outData << -1 << " ";
      if(y % 2 == 1)
        outData << endl;
    }
  }
  else
  {
    outData << -1 << " " << -1 << endl;
    outData << -1 << " " << -1 << endl;
  }

  //Red pieces
  if(findPiece(spots, RED, GENERAL, coordinate))
  {
    outData << coordinate[0] << " " << coordinate[1] << endl;
  }
  else
  {
    outData << -1 << " " << -1 << endl;
  }
  if(findPiece(spots, RED, ADVISOR, coordinate))
  {
    outData << coordinate[0] << " " << coordinate[1] << endl;
    if(coordinate.size() == 2)
      outData << -1 << " " << -1 << endl;
    else
      outData << coordinate[2] << " " << coordinate[3] << endl;
  }
  else
  {
    outData << -1 << " " << -1 << endl;
    outData << -1 << " " << -1 << endl;
  }
  if(findPiece(spots, RED, ELEPHANT, coordinate))
  {
    outData << coordinate[0] << " " << coordinate[1] << endl;
    if(coordinate.size() == 2)
      outData << -1 << " " << -1 << endl;
    else
      outData << coordinate[2] << " " << coordinate[3] << endl;
  }
  else
  {
    outData << -1 << " " << -1 << endl;
    outData << -1 << " " << -1 << endl;
  }
  if(findPiece(spots, RED, HORSE, coordinate))
  {
    outData << coordinate[0] << " " << coordinate[1] << endl;
    if(coordinate.size() == 2)
      outData << -1 << " " << -1 << endl;
    else
      outData << coordinate[2] << " " << coordinate[3] << endl;
  }
  else
  {
    outData << -1 << " " << -1 << endl;
    outData << -1 << " " << -1 << endl;
  }
  if(findPiece(spots, RED, CHARIOT, coordinate))
  {
    outData << coordinate[0] << " " << coordinate[1] << endl;
    if(coordinate.size() == 2)
      outData << -1 << " " << -1 << endl;
    else
      outData << coordinate[2] << " " << coordinate[3] << endl;
  }
  else
  {
    outData << -1 << " " << -1 << endl;
    outData << -1 << " " << -1 << endl;
  }
  if(findPiece(spots, RED, CANNON, coordinate))
  {
    outData << coordinate[0] << " " << coordinate[1] << endl;
    if(coordinate.size() == 2)
      outData << -1 << " " << -1 << endl;
    else
      outData << coordinate[2] << " " << coordinate[3] << endl;
  }
  else
  {
    outData << -1 << " " << -1 << endl;
    outData << -1 << " " << -1 << endl;
  }
  if(findPiece(spots, RED, SOLDIER, coordinate))
  {
    for(int x = 0; x < coordinate.size(); x++)
    {
      outData << coordinate[x] << " ";
      if(x % 2 == 1)
        outData << endl;
    }
    for(int y = coordinate.size(); y < 10; y++)
    {
      outData << -1 << " ";
      if(y % 2 == 1)
        outData << endl;
    }
  }
  else
  {
    outData << -1 << " " << -1 << endl;
    outData << -1 << " " << -1 << endl;
  }

  outData.close();
}

#endif
