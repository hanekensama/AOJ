#include <bits/stdc++.h>
#define int long long
using namespace std;

int span(int a, int m) {
  int cnt = 1;
  int x = a % m;
  while(x != 1) {
    x = (a * x) % m;
    cnt++;
  }
  return cnt;
}

int gcd(int m, int n) {
  if ((m == 0) || (n == 0)) return 0;
  int r = 1;
  while(r != 0) {
    r = m % n;
    m = n;
    n = r;
  }
  return m;
}

int lcm(int m, int n) {
  if ((m == 0) || (n == 0)) return 0;
  return (m * n) / gcd(m, n);
}

int solve(vector<int> a, vector<int> m) {
  vector<int> s(3);
  for (auto i = 0; i < 3; i++) {
    s[i] = span(a[i], m[i]);
  }
  
  int ans = lcm(s[0], s[1]);
  ans = lcm(ans, s[2]);

  return ans;
}

signed main() {
  vector<int> a(3), m(3);
  int a1, m1, a2, m2, a3, m3;
  while(cin >> a[0] >> m[0] >> a[1] >> m[1] >> a[2] >> m[2], a[0] != 0) {
    cout << solve(a, m) << endl;
  }
  
  return 0;
}
