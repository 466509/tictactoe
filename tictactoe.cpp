#include <iostream>

using namespace std;

void printArray(char arr[3][3]);
void makeMove(int& x, int& y);
bool isLegal(char arr[3][3], int x, int y);
bool checkWin(char arr[3][3], int& player1wins, int& player2wins);

int main() {
  char arr[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
  char (*ptr)[3] = arr;
  char play = 'y';
  int turn = 0;
  int player1wins = 0;
  int player2wins = 0;
  printArray(arr);

  while (play == 'y') {
    char symb;
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
      makeMove(row, col);
      if (isLegal(arr, row-1, col-1)) {
	arr[row-1][col-1] = symb;
	printArray(arr);
	legal = true;
      } else {
	cout << "Move not valid!" << endl;
      }
    }
    turn++;
    if (checkWin(arr, player1wins, player2wins)) {
      play = 'n';
    }
  }
  return 0;
}

void printArray(char arr[3][3]) {
  for (int a=0; a<3; a++) {
    for (int b=0; b<3; b++) {
      cout << arr[a][b] << " ";
    }
    cout << endl;
  }
}

void makeMove(int& row, int& col) {
  cout << "Which row? (1, 2, or 3) ";
  cin >> row;
  cout << "Which column? (1, 2, or 3) ";
  cin >> col;
}

bool isLegal(char arr[3][3], int x, int y) {
  if (x < 3 && y < 3 && arr[x][y] == ' ') {
    return true;
  }
  else {
    return false;
  }
}

bool checkWin(char arr[3][3], int& player1wins, int& player2wins) {
  cout<<"checking win" << endl;
  if (arr[1][1]!=' ' && arr[0][0]==arr[1][1]==arr[2][2] || arr[2][0]==arr[1][1]==arr[0][2]) {
      if (arr[1][1]=='X') {
	cout << "Player 1 wins!" << endl;
	player1wins++;
      } else {
	cout << "Player 2 wins!" << endl;
	player2wins++;
      }
      return true;
  }
  return false;
}
