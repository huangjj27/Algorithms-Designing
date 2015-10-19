// original from http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=27798
#include<cstdio>
int main() {
  for (int n = 1000000;;) {
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        for (int k = 0; k < 26; k++) {
          if (n-- > 0) printf("%c", 'a' + i);
          if (n-- > 0) printf("%c", 'a' + j);
          if (n-- > 0) printf("%c", 'a' + k);
          else return 0;
        }
      }
    }
  }

  return 0;
}
