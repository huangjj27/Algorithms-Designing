#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  char str[20], length;
  int k;
  while (scanf("%s %d", str, &k) != EOF) {
    length = 0;
    while(str[length] != '\0') length++;
    sort(str, str+length);
    for (int i = 0; i < k - 1; i++) {
      next_permutation(str, str+length);
    }
    
    printf("%s\n", str);
  }
  return 0;
}

