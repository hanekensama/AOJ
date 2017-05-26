#include <bits/stdc++.h>
using namespace std;

inline int tax(int p, int x) {
  return (p * (100 + x)) / 100;
}

int solve(int x, int y, int s) {
  int mx = INT_MIN;
  for (int a = 1; a < s; ++a) {
    for (int b = 1; b < s; ++b) {
      auto s_ = tax(a, x) + tax(b, x);
      if (s_ < s) continue;
      else if (s_ == s) {
	mx = max(mx, tax(a, y) + tax(b, y));
      }
      else break;
    }
  }
  return mx;
}

int main() {
  int x, y, s;
  while(cin >> x >> y >> s, x | y | s)
    cout << solve(x, y, s) << endl;
  return 0;
}
