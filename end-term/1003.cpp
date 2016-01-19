#include <cstdio>
#include <algorithm>
#define MAX 100000

using namespace std;

int main() {
  int N, H;
  while (scanf("%d %d", &N, &H) != EOF) {
    int pos[MAX+5], count = 1;
    for (int i = 0; i < N; i++) scanf("%d", &pos[i]);
    sort(pos, pos+N);
    for (int i = 1; i < N; i++) {
      if (pos[i] - pos[i-1] >= H) count++;
    }
    
    printf("%d\n", count);
  }
  return 0;
}

