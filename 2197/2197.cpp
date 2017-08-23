#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
  int cnt = 0;
  for (int i = 1;i <= n / 2; i++) {
    int m = 0;
    int j = i;
    while(m < n) m += j++;
    if (m == n)  cnt++;
  }
  return cnt;
}

int main() {
  int n;
  while(cin >> n, n) {
    cout << solve(n) << endl;
  }
  return 0;
}
