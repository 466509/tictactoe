#include <iostream>
using namespace std;

void printArray(char arr[3][3]);
void makeMove(char& x, int& y);
bool isLegal(char arr[3][3], int x, int y);
bool checkWin(char arr[3][3], int& player1wins, int& player2wins);
bool checkTie(char arr[3][3]);

int main() {
  char play = 'y';
  int player1wins = 0;
  int player2wins = 0;
  char arr[3][3] = {{' ', ' ', ' '},{' ', ' ', ' '},{' ', ' ', ' '}};
  printArray(arr);

  while (play == 'y') {
    for (int i=0; i<3; i++) {
      for (int j=0; j<3; j++) {
        arr[i][j] = ' ';
      }
    }
    int turn = 0;
    bool gameover = false;
    while (!gameover) {
      char symb;
      char rowchar;
      int row;
      int col;
      bool legal = false;
      if (turn%2 == 0) {
        symb = 'X';
        cout << "Player 1 (X) turn" << endl;
      } else {
        symb = 'O';
        cout << "Player 2 (O) turn" << endl;
      }
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
      turn++;
      if (checkWin(arr, player1wins, player2wins)) {
        cout << "Player 1 wins: " << player1wins << endl;
        cout << "Player 2 wins: " << player2wins << endl;
        cout << "Play again? (y/n) ";
        cin >> play;
        gameover = true;
      } 
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
  return 0;
}

void printArray(char arr[3][3]) {
  cout << "  1 2 3" << endl;
  for (int a=0; a<3; a++) {
    char rowlabel = 'a' + a;
    cout << rowlabel << " ";
    for (int b=0; b<3; b++) {
      cout << arr[a][b] << " ";
    }
    cout << endl;
  }
}

void makeMove(char& row, int& col) {
  cout << "Which row? (a, b, or c) ";
  cin >> row;
  cout << "Which column? (1, 2, or 3) ";
  cin >> col;
}

bool isLegal(char arr[3][3], int x, int y) {
  if (x < 3 && x >= 0 && y >= 0 && y < 3 && arr[x][y] == ' ') {
    return true;
  }
  else {
    return false;
  }
}

bool checkWin(char arr[3][3], int& player1wins, int& player2wins) {
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

bool checkTie(char arr[3][3]) {
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      if (arr[i][j] == ' ') {
        return false;
      }
    }
  }
  return true;
}

