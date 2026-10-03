#include <iostream>
using namespace std;

// function prototypes
void printArray(char arr[3][3]);
void makeMove(char& x, int& y);
bool isLegal(char arr[3][3], int x, int y);
bool checkWin(char arr[3][3], int& player1wins, int& player2wins);
bool checkTie(char arr[3][3]);

int main() {
  char play = 'y';
  int player1wins = 0;
  int player2wins = 0;
  
  // initialize an empty 3x3 board
  char arr[3][3] = {{' ', ' ', ' '},{' ', ' ', ' '},{' ', ' ', ' '}};
  printArray(arr);

  // main game loop
  while (play == 'y') {
    // clear board
    for (int i=0; i<3; i++) {
      for (int j=0; j<3; j++) {
        arr[i][j] = ' ';
      }
    }
    int turn = 0;
    bool gameover = false;
    // turn loop for a single game
    while (!gameover) {
      char symb;
      char rowchar;
      int row;
      int col;
      bool legal = false;
      // determine player symbol ('X' on even turns, 'O' on odd turns)
      if (turn%2 == 0) {
        symb = 'X';
        cout << "Player 1 (X) turn" << endl;
      } else {
        symb = 'O';
        cout << "Player 2 (O) turn" << endl;
      }

      // allow player to make a move, and let them try again if it's not valid
      while (legal == false) {
        makeMove(rowchar, col);
        row = rowchar - 'a'; // convert a to 0, b to 1, c to 2
        if (isLegal(arr, row, col-1)) {
          arr[row][col-1] = symb;
          printArray(arr);
          legal = true;
        } else {
          cout << "Move not valid!" << endl;
        }
      }
      turn++; // next turn

      // check to see if current move won the game
      if (checkWin(arr, player1wins, player2wins)) {
        cout << "Player 1 wins: " << player1wins << endl;
        cout << "Player 2 wins: " << player2wins << endl;
        cout << "Play again? (y/n) ";
        cin >> play;
        gameover = true; // end the current game loop
      } 
      // check to see if board is full without a winner
      else if (checkTie(arr)) {
        cout << "Player 1 wins: " << player1wins << endl;
        cout << "Player 2 wins: " << player2wins << endl;
        cout << "It's a tie!" << endl;
        cout << "Play again? (y/n) ";
        cin >> play;
        gameover = true;
      }
    }
  }
  cout << "Thanks for playing!" << endl;
  return 0;
}

// Outputs board with rows labeled a b and c, columns labeled 1, 2, 3
void printArray(char arr[3][3]) {
  cout << "  1 2 3" << endl; // Column labels
  for (int a=0; a<3; a++) {
    char rowlabel = 'a' + a; // use ASCII values to turn a into 0
    cout << rowlabel << " ";
    for (int b=0; b<3; b++) {
      cout << arr[a][b] << " ";
    }
    cout << endl;
  }
}

// Handles user input and lets them pick a spot
void makeMove(char& row, int& col) {
  cout << "Which row? (a, b, or c) ";
  cin >> row;
  cout << "Which column? (1, 2, or 3) ";
  cin >> col;
}

// Checks if move is legal
bool isLegal(char arr[3][3], int x, int y) {
  // Has to be within the 3x3 grid and be currently empty
  if (x < 3 && x >= 0 && y >= 0 && y < 3 && arr[x][y] == ' ') {
    return true;
  }
  else {
    return false;
  }
}

// Checks horizonal, vertical, and diagonal win conditions
bool checkWin(char arr[3][3], int& player1wins, int& player2wins) {
  // check diagonals
  if (arr[1][1]!=' '){
    bool diag1 = (arr[0][0]==arr[1][1]&& arr[1][1]==arr[2][2]);
    bool diag2 = (arr[2][0]==arr[1][1] && arr[1][1]==arr[0][2]);
    if(diag1||diag2) {
      if (arr[1][1]=='X') {
	cout << "Player 1 wins!" << endl;
	player1wins++;
      } else {
	cout << "Player 2 wins!" << endl;
	player2wins++;
      }
      return true;
    }
  }

  // Checks rows
  for (int i=0; i<3; i++) {
    if (arr[i][0] != ' ' && arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) {
      if (arr[i][0]=='X') {
        cout << "Player 1 wins!" << endl;
        player1wins++;
      } else {
        cout << "Player 2 wins!" << endl;
        player2wins++;
      }
      return true;
    }
  }

  // Checks columns
   for (int j=0; j<3; j++) {
     if (arr[0][j] != ' ' && arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j]) {
       if (arr[0][j] == 'X') {
         cout << "Player 1 wins!" << endl;
         player1wins++;
       } else {
         cout << "Player 2 wins!" << endl;
         player2wins++;
       }
     return true;
     }
   }
   return false;
}

// Checks for a tie
// Returns true if all cells are filled
bool checkTie(char arr[3][3]) {
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      if (arr[i][j] == ' ') {
        return false; // Found an empty spot, not a tie
      }
    }
  }
  return true; // Board is full
}

