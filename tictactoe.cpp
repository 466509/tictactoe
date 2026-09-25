#include <iostream>

using namespace std;

void printArray(char arr[][3]);
//void printPointer(int** arrPtr);

int main() {
  char arr[3][3] = {'x'};
  char (*ptr)[3] = arr;
  char play = 'y';
  while (play == 'y') {
    printArray(arr);
    int turn = 0;
    char symb;
    char row;
    if (turn%2 == 0) {
      symb = 'X';
    } else {
      symb = 'O';
    }
    cout << "Which row? (a, b, or c)" << " ";
    cin >> row;
    cout << turn << endl;
    turn++;
  }

  /*
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      arr[i][j] = 0;
    }
  }
  
  int** arrPtr = new int*[3];
  for (int a=0; a<3; a++) {
    arrPtr[a] = new int[3];
    for (int b=0; b<<3; b++) {
      arrPtr[a][b] = 0;
    }
  }
  arrPtr[1][1] = 67;
  printArray(arr);
  printPointer(arrPtr);
  */
  
  return 0;
}

void printArray(char arr[][3]) {
  for (int a=0; a<3; a++) {
    for (int b=0; b<3; b++) {
      cout << arr[a][b] << " ";
    }
    cout << endl;
  }
}

/*
void printPointer(int** arrPtr) {
  for (int a=0; a<3; a++) {
    for (int b=0; b<3; b++) {
      cout << arrPtr[a][b] << " ";
    }
    cout << endl;
  }
}
*/
