#include <bits/stdc++.h>
using namespace std;

bool primes[1000000];
void Prime(){
  primes[0] = false; primes[1] = false;
  for (int i = 2; i < 1000000; i++) primes[i] = true;
  for (int i = 2; i < 1000; i++) {
    if (primes[i]) {
      for (int j = i * 2; j < 1000000; j += i) primes[j] = false;
    }
  }
}

int main() {
  Prime();
  int n;
  while(cin >> n) {
    int cnt = 0;
    for (int i = 2; i <= n; i++) if (primes[i]) cnt++;
    cout << cnt << endl;
  }
  return 0;
} 
