#include <bits/stdc++.h>
using namespace std;

void solve(const vector<int>& v) {
  string result;
  auto a = -1;
  auto begin = -1;
  for (auto i = 0; i < v.size(); ++i) {
    if (v[i] != a + 1) {
      begin = v[i];
      result += to_string(begin) + "-" + to_string(a) + " ";
    }
    a = v[i];
  }

  return result.pop_back();
}

int main() {
  int n;
  while(cin >> n, n) {
    vector<int> v(n);
    for (auto i = 0; i < n; ++i) cin >> v[i];
    solve(v);
  }
  
  return 0;
}
