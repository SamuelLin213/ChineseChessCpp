#include <iomanip>
#include <iostream>
using namespace std;

int printMenu();

int main()
{
  int choice = 0;

  while(choice != 3)
  {
    // do{
    //   choice = printMenu();
    // }while(choice < 1 || choice > 3);
    choice = printMenu();
    if(choice < 1 || choice > 3)
    {
      cout << "Error: invalid choice! Please enter a choice between 1 and 3";
      cin.ignore();
      cin.get();

      continue;
    }

    switch(choice)
    {
      case 1:
      {

        break;
      }
      case 2:
      {

        break;
      }
      case 3:
      {
        cout << "Exiting the program!" << endl;
        break;
      }
      default:
      {
        cout << "Error: invalid choice! Please enter a choice between 1 and 3";
        cin.ignore();
        cin.get();
      }
    }

  }

  return 0;
}

int printMenu()
{
  int choice = 0;

  cout << "\033[2J\033[1;1H"; //Clears the terminal screen
  cout << "1. Start new game" << endl;
  cout << "2. Load saved game" << endl;
  cout << "3. Quit" << endl;

  cout << endl << "Please enter a choice: ";

  cin >> choice;

  if(cin.fail())
  {
    cin.clear();
    cin.ignore();

    return -1;
  }

  return choice;
}
