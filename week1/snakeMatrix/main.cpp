// Copyright (c) 2015 HuangJunjie@SYSU(SNO:13331087). All Rights Reserved.
// fills a matrix with sanke-like order. From outside to inside laps.
// each lap is in the order of from right top in clockwise direction.
#define MAX_SIZE 20
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

// fill the matrix with snake nummbers.
// @Param n: the nummber of each edge
// @Param snake: the matrix to be filled
void getSnake(int n, int snake[MAX_SIZE + 5][MAX_SIZE + 5]) {
  int count = 1; // the number to fill an element of the matrix
  // the outsied i-th lap.
  for (int i = 1; i <= (n + 1) / 2; i++) {
    // fills the right edge
    for (int col = n + 1 - i, row = i; row <= n - i; row++) {
      snake[row][col] = count++;
    }

    // fills the down edge
    for (int col = n + 1 - i, row = n + 1 - i; col >= i; col--) {
      snake[row][col] = count++;
    }

    // fills the left edge
    for (int col = i, row = n - i; row >= i + 1; row--) {
      snake[row][col] = count++;
    }

    // fills the up edge
    for (int col = i, row = i; col < n + 1 - i; col++) {
      snake[row][col] = count++;
    }
  }
}


// output the matrix to the screen
// @Param snake: the matrix to print
// @Param n: the size of the matrix
void printSnake(int snake[MAX_SIZE + 5][MAX_SIZE + 5], int n) {
  for (int row = 1; row <= n; row++) {
    for (int col = 1; col <= n; col++) {
      if (col > 1) cout << "\t";
      cout << snake[row][col];
    }
    cout << endl;
  }
}

// reset the matrix
// @Param snake: the matrix to reset
void resetSnake(int snake[MAX_SIZE + 5][MAX_SIZE + 5]) {
  for (int i = 0; i < MAX_SIZE + 5; i++) {
    memset(snake[i], 0, (MAX_SIZE + 5)* sizeof(int));
  }
}

int main() {
  int snake[MAX_SIZE + 5][MAX_SIZE + 5] = { 0 };

  int n;
  while (scanf("%d", &n) != EOF) {
    getSnake(n, snake);
    printSnake(snake, n);
    resetSnake(snake);
    cout << endl;
  }

  return 0;
}
