// Copyright (c) 2015 HuangJunjie@SYSU(SNO:13331087). All Rights Reserved.
#define ALPHA_SIZE 26
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>

#include <cstdio>
#include <string>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int state;
  string opt;
} start;

bool isvisited[40320] = { 0 };
string opts[40320];         // operation records
int factor[8] = { 1, 1, 2, 6, 24, 120, 720, 5040 };

Node doA(const Node& node);
Node doB(const Node& node);
Node doC(const Node& node);

int contor(Node current);

fstream testcase;
fstream answer;

void init();
void makeTestCase(int cases);
void build();
void bfs(Node aim);

Node recontor(int i);

int main() {
  init();

  for (int cases = 10; cases < 10000; cases *= 10) {
    makeTestCase(cases);
  }
  for (int cases = 50; cases < 50000; cases *= 10) {
    makeTestCase(cases);
  }

  return 0;
}

void init() {
  srand(time(NULL));
  start.state = 12348765;
  start.opt = "";

  build();
}

void build() {
  for (int i = 0; i < 40320; i++) {
    if (opts[i] == "") {
      Node aim = recontor(i);
      bfs(aim);
    }
  }
}

void bfs(Node aim) {
  memset(isvisited, 0, sizeof(isvisited));
  queue<Node> que;
  que.push(start);
  while (!que.empty()) {
    Node current = que.front();
    que.pop();
    if (isvisited[contor(current)] == true) {
      continue;
    } else {
      isvisited[contor(current)] = true;

      // stores the operation path.
      if (opts[contor(current)] == "")
        opts[contor(current)] = current.opt;
    }

    if (contor(current) == contor(aim)) {
      return;
    }

    Node Anext = doA(current);
    que.push(Anext);
    Node Bnext = doB(current);
    que.push(Bnext);
    Node Cnext = doC(current);
    que.push(Cnext);
  }
}

void makeTestCase(int cases) {
  char buf[5];
  sprintf(buf, "%d", cases);
  string cases_str = buf;
  string inputname = "input" + cases_str + ".txt";
  string answername = "answer" + cases_str + ".txt";
  testcase.open(inputname, ios::out);
  answer.open(answername, ios::out);

  for (int i = 0; i < cases; i++) {
    int steps = rand() % cases;

    testcase << steps << endl;
    int key = rand() % 40320;

    Node test = recontor(key);

    for (int factor = 10000000; factor; factor /= 10) {
      if (factor != 10000000 && factor != 1000) testcase << " ";
      if (factor == 1000) testcase << endl;
      testcase << test.state / factor;
      test.state %= factor;
    }
    testcase << endl;

    answer << opts[key].size() << " " << opts[key] << endl;
  }
  testcase << -1 << endl;

  testcase.close();
  answer.close();
}

Node doA(const Node& node) {
  Node Anext;
  Anext.state = node.state % 10000 * 10000 + node.state / 10000;
  Anext.opt = node.opt + 'A';

  return Anext;
}

Node doB(const Node& node) {
  Node Bnext;
  int up = node.state / 10000;
  int down = node.state % 10000;
  Bnext.state = (up / 10 + up % 10 * 1000) * 10000 + (down / 10 + down % 10 * 1000);
  Bnext.opt = node.opt + 'B';

  return Bnext;
}

Node doC(const Node& node) {
  Node Cnext;
  int fact = 10000000;
  int temp[8];
  for (int i = 0; i < 8; i++) {
    temp[i] = (node.state / fact) % 10;
    fact /= 10;
  }

  Cnext.state = (temp[0] * 1000 + temp[5] * 100 + temp[1] * 10 + temp[3]) * 10000 +
    (temp[4] * 1000 + temp[6] * 100 + temp[2] * 10 + temp[7]);
  Cnext.opt = node.opt + 'C';

  return Cnext;
}

int contor(Node current) {
  int fact = 10000000;
  int temp[8];
  for (int i = 0; i < 8; i++) {
    temp[i] = (current.state / fact) % 10;
    fact /= 10;
  }

  int sum = 0;
  for (int i = 0; i < 8; i++) {
    int count = 0;
    for (int j = i + 1; j < 8; j++) {
      if (temp[i] > temp[j]) count++;
    }
    sum += count*factor[7 - i];
  }

  return sum;
}

Node recontor(int key) {
  Node result;
  result.state = 0;
  bool num[8] = { 0 };
  for (int i = 7; i >= 0; i--) {
    int count = -1;
    int remain = key / factor[i];
    key %= factor[i];
    for (int j = 0; j < 8; j++) {
      if (num[j] == false) count++;
      if (count == remain) {
        num[j] = true;
        result.state *= 10;
        result.state += j + 1;
        break;
      }
    }
  }

  return result;
}
