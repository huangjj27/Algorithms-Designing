// unpassed code: WA
#include <cstdio>
#define MAX 14

int main() {
  int T, N;
  scanf("%d", &T);
  for (int cases = 1; cases <= T; cases++) {
    int n, matrix[MAX+1][MAX+1] = { 0 };
    int max[MAX+1] = { 0 }, oppent[MAX+1] = { 14 };
    bool visited[MAX+1] =  { false };
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        scanf("%d", &matrix[i][j]);
        if (j > i && (!visited[i] && !visited[j]) && matrix[i][j] > max[i]) {
          max[i] = matrix[i][j];
          oppent[i] = j;
          oppent[j] = i;
        }
        
        visited[i] = visited[oppent[i]] = true;
      }
    }
    
    int sum = 0;
    for (int i = 0; i < N; i++) sum += max[i];
      
    printf("Case #%d: %d\n", cases, sum);
  }
  return 0;
}

