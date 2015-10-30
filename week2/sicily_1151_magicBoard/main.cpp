// Copyright (c) 2015 HuangJunjie@SYSU(SNO:13331087). All Rights Reserved.
// 1151 魔板: http://soj.sysu.edu.cn/1151
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

struct Node {
  int state;
  string opt;
};

bool isvisited[40320] = { 0 };  // checks if a state is visited
string opts[40320];             // operation records
// help to count the contor value
int factor[8] = { 1, 1, 2, 6, 24, 120, 720, 5040 };

Node doA(const Node& node);
Node doB(const Node& node);
Node doC(const Node& node);

int contor(Node current);

int main() {
  int max_steps;
  Node aim;

  // initialized the start node
  Node start;
  start.state = 12348765;
  start.opt = "";

  while (scanf("%d", &max_steps) != EOF && max_steps != -1) {
    int digit;
    aim.state = 0;
    for (int i = 0; i < 8; i++) {
      scanf("%d", &digit);
      aim.state *= 10;
      aim.state += digit;
    }

    if (opts[contor(aim)] != "") {
      printf("%d %s\n", opts[contor(aim)].size(), opts[contor(aim)].c_str());
      continue;
    }

    memset(isvisited, 0, sizeof(isvisited));
    queue<Node> que;
    que.push(start);
    while (!que.empty()) {
      Node current = que.front();
      que.pop();

      // if the current node has been visited?
      if (isvisited[contor(current)] == true) {
        continue;
      } else {
        isvisited[contor(current)] = true;    // now it is visited.

        // stores the operation path.
        if (opts[contor(current)] == "")
          opts[contor(current)] = current.opt;
      }

      // can't find within max_steps
      if (current.opt.size() > max_steps) {
        printf("-1\n");
        break;
      }

      // found!
      if (contor(current) == contor(aim)) {
        printf("%d %s\n", current.opt.size(), current.opt.c_str());
        break;
      }

      // expand the queue
      Node Anext = doA(current);
      que.push(Anext);
      Node Bnext = doB(current);
      que.push(Bnext);
      Node Cnext = doC(current);
      que.push(Cnext);
    }
  }

  return 0;
}

// the three type operations
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

// computes the contor value of the current node
// different node states indicate different contor values
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
