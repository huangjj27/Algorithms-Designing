// Copyright (c) 2015 HuangJunjie@SYSU(SNO:13331087). All Rights Reserved.
// original from http://acm.hust.edu.cn/vjudge/contest/view.action?cid=93703#problem/G
#include <cstdio>

#define MAX 1000

int g(int eggs, int floors);

int main() {
  int eggs, floors;
  while (scanf("%d %d", &eggs, &floors) != EOF && (eggs && floors)) {
    printf("%d\n", g(eggs, floors));
  }

  return 0;
}

int g(int eggs, int floors) {
  int matrix[MAX + 5][MAX + 5] = { 0 };
  for (int i = 0; i <= MAX; i++) {
    matrix[1][i] = 1;
    matrix[i][1] = i;
  }

  if (eggs == 1) return floors;
  if (floors == 1) return 1;
  for (int trial = 1; trial <= floors; trial++) {
    for (int egg = 1; egg <= eggs; egg++) {
      if (trial > 1 && egg > 1) {
        matrix[trial][egg] = matrix[trial - 1][egg - 1] + matrix[trial - 1][egg] + 1;
        if (matrix[trial][egg] >= floors && matrix[trial-1][egg] < floors)
          return trial;
      }
    }
  }
}
