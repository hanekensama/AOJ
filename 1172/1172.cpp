#include <bits/stdc++.h>
using namespace std;
#define MAX (123456 * 2)

bool primes[MAX + 1];

void init() {
  primes[0] = false;
  primes[1] = false;
  for (int i = 2; i <= MAX; i++)
    primes[i] = true;

  int end = sqrt(MAX + 1);
  for (int i = 2; i <= end; i++)
    if (primes[i])
      for (int j = i * 2; j <= MAX; j += i)
	primes[j] = false;
}

int solve(int n) {
  int cnt = 0;
  for (int i = n + 1; i <= 2 * n; i++)
    if (primes[i]) cnt++;
    
  return cnt;
}

int main() {
  init();
  int n;
  while(cin >> n, n) {
    cout << solve(n) << endl;
  }
}
