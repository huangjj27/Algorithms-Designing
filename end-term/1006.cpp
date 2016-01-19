// unpassed code : TLE
#include <cstdio>
#define MAX 14

bool is_prime(int n) {
  if (n <= 1) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (int i = 3; i*i < n; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}

int get_prime_factors(int n) {
  int factor = 0;
  while (n % 2 == 0) {
    n /= 2;
    factor++;
  }
  for (int i = 3; n > 1; i += 2) {
    if(is_prime(i)) {
      while (n % i == 0) {
        factor++;
        n /= i;
      }
    }
  }
  return factor;
}

int main() {
  int T, N;
  scanf("%d", &T);
  for (int cases = 1; cases <= T; cases++) {
    int N, factors, K;
    scanf("%d %d", &N, &K);
    factors = get_prime_factors(N);
    
    factors == K ? printf("Yes\n") : printf("No\n");
  }
  return 0;
}

