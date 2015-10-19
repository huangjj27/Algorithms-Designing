// Copyright (c) 2015 HuangJunjie@SYSU(SNO:13331087). All Rights Reserved.
// original from http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=27826
#include <cstdio>

#define MAX_SIZE 3000
#define MOD 100000000

int answer[MAX_SIZE + 1] = { 0 };
int highest = 0;      // the index to find the most significant element

void multiply3() {
  int carry = 0;
  for (int i = 0; i <= highest; i++) {
    int remain = (answer[i] * 3 + carry) % MOD;
    carry = (answer[i] * 3 + carry) / MOD;
    answer[i] = remain;
    if (i == highest && carry) highest++;
  }
}

void output() {
  printf("%d", answer[highest]);
  for (int i = highest - 1; i >= 0; i--) printf("%08d", answer[i]);
  printf("\n");
}

int main() {
  int N;
  scanf("%d", &N);
  answer[0] = N % 3;
  N -= answer[0];

  if (answer[0] <= 1 && N >= 3) {
    answer[0] += 3;
    N -= 3;
  }

  while (N) {
    multiply3();
    N -= 3;
  }

  output();
  return 0;
}
