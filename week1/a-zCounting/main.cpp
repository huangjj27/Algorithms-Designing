// Copyright (c) 2015 HuangJunjie@SYSU(SNO:13331087). All Rights Reserved.
// for some given strings ended with '?', counts the appearence times of letters
#define ALPHA_SIZE 26
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// count the times of each letter's appearance.
// @Param input: the input stream of file or cin
// @Param output: the integer array of the counted apearance times of letters
void alphaCount(istream& input, int* count) {
  char ch;

  // each test case is a line.
  while (input >> ch && ch != '?') {
    if (isalpha(ch)) {
      isupper(ch) ? count[ch - 'A']++ : count[ch - 'a']++;
    }
  }
}

// outputs a testcase's counting data to the output stream
// @Param count: the the integer array of the counted apearance times of letters
// @Param test_case: the number of the current test case
// @Param output: the output stream of file or cout.
void printCount(int* count, int test_case, ostream& output) {
  if (test_case > 1) output << endl;
  output << "test case: " << test_case << endl;

  for (int i = 0; i < ALPHA_SIZE; i++) {
    if (i) output << " ";
    if (i == ALPHA_SIZE/2) output << endl;
    output << (char)('a' + i) << ": " << count[i];
    count[ALPHA_SIZE] += count[i];
  }
  output << endl;
  output << "count: " << count[ALPHA_SIZE] << endl;
}

int main() {
  int count[ALPHA_SIZE + 1] = { 0 };

  ifstream instream;
  ofstream outstream;

  instream.open("input.txt");
  outstream.open("output.txt");

  for (int i = 0; i < 5; i++) {
    alphaCount(instream, count);
    printCount(count, i+1, outstream);
    memset(count, 0, (ALPHA_SIZE+1) * sizeof(*count));
  }

  instream.close();
  outstream.close();

  return 0;
}
