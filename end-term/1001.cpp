#include <cstdio>

long long GCD(long long a,long long b) {
  if (b == 0) return a;
  return GCD(b, a%b);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    int n;
    long long temp, gcd;
    scanf("%d", &n);
    
    for (int j = 0; j < n; j++) {
      scanf("%lld", &temp);
      if (!j) gcd = temp;
      else gcd = GCD(gcd, temp);
    }
    
    printf("%lld\n", gcd);
  }
  return 0;
}

