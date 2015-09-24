// Copyright (c) 2015 HuangJunjie@SYSU(SNO:13331087). All Rights Reserved.
#define ALPHA_SIZE 26
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

int main() {
  srand(time(NULL));
  fstream testcase;
  testcase.open("input.txt", ios::out);
  for (int length = 10; length <= 100000; length *= 10) {
    for (int i = 0; i < length; i++) {
      bool isupper = rand() % 2;
      char ch = isupper ? ('A' + rand() % 26) : ('a' + rand() % 26);
      testcase << ch;
    }
    testcase << '?' << endl;
  }
  return 0;
}
