#include "enums.h"
#include "game.h"
using namespace std;

int printMenu(); // forward declaration
void readGame(); // load saved game
void writeGame(); // save current game

int main()
{
  int choice = 0; //stores the option that user chooses

  while(choice != 3) //loops as long as user doesn't choose the option to quit
  {
    choice = printMenu(); // calls function to print menu, and stores the resulting choice into var
    if(choice < 1 || choice > 3) // if the resulting choice is out of bounds, let user know
    {
      cout << "Error: invalid choice! Please enter a choice between 1 and 3";
      // waits for user to press any key, to continue
      cin.ignore();
      cin.get();

      continue;
    }

    // Branches out depending on user choice
    switch(choice)
    {
      case 1: // Choice to start new game
      {
        choice = playGame(1);
        break;
      }
      case 2: // Choice to continue saved game
      {
        choice = playGame(2);
        break;
      }
      case 3: // Choice to exit program
      {
        cout << "Exiting the program!" << endl;
        break;
      }
    }

  }

  return 0;
}

int printMenu()
{
  int choice = 0;

  clearScreen();
  cout << "1. Start new game" << endl;
  cout << "2. Load saved game" << endl;
  cout << "3. Quit" << endl;

  // Prompts for user input
  cout << endl << "Please enter a choice: ";
  cin >> choice;

  // When user inputs non-integers
  if(cin.fail())
  {
    // Resets the failed cin buffer
    cin.clear();
    cin.ignore();

    return -1; // By returning a negative, the loop in main() will output the error message about invalid input
  }

  return choice;
}
