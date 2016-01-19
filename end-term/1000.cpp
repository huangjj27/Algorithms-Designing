#include <cstdio>
#include <algorithm>

#define MAX 10000

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    int n,x[MAX + 5] = { 0 };
    scanf("%d", &n);
    
    for (int j = 0; j < n; j++) {
      scanf("%d", &x[j]);
    }
    std::sort(x, x+MAX+5);
    
    printf("Case #%d: %d\n", i, x[MAX+4] + x[MAX+3] + x[MAX+2]);
  }
  return 0;
}

