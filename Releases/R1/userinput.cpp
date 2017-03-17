#include <ncurses.h> 							//	Imports the NCurses library
#include <iostream>								//	Creates IO Stream within terminal
#include <string.h>								//	Allows me to manipulate strings

using namespace std;							//	Simplify an instance of the standard functions

string Input() {								//	Define Function Input
  initscr();									// 	initalises the curses mode
  noecho();										//	avoids double input/output
  while (true) {								// 	creates the while loop to wait for user input
    char userKey = getch();						//	creates a varible to store the received input from user
    if (userKey == 'w') {						//	If the user presses W then it will return W. 
      return "w";
    }
    if (userKey == 'a') {						//	If the user presses A then it will return A. 
      return "a";
    }
    if (userKey == 's') {						//	If the user presses S then it will return S. 
      return "s";
    }
    if (userKey == 'd') {						//	If the user presses D then it will return D. 
      return "d";
    }
    if (userKey == 'q') {						//	If the user presses Q then it will return Q. This is used to quite the game
      return "q";
    }
  }
}

int main() {
  while (true) {
    string key = Input();						//	assigning varible
    cout << "You Pressed " << key << endl;		//	outputting pressed key
  }
}

// KISHAN
// 