#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; ++i)

using namespace std;

int solve(vector<int>& v) {
  sort(v.begin(), v.end());
  auto mn = INT_MAX;
  for (auto i = 1; i < v.size(); ++i) mn = min(v[i] - v[i - 1], mn);
  return mn;
}

int main() {
  int n;
  while(cin >> n, n) {
    vector<int> v(n);
    REP(i, n) cin >> v[i];
    cout << solve(v) << endl;
  }
}
