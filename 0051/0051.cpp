#include <bits/stdc++.h>
using namespace std;

int solve(string s) {
  sort(s.begin(), s.end());
  int mn = stoi(s);
  sort(s.begin(), s.end(), greater<char>());
  int mx = stoi(s);
  return mx - mn;
}

int main() {
  int n;
  cin >> n;
  for (auto i = 0; i < n; ++i) {
    string s;
    cin >> s;
    cout << solve(s) << endl;
  }
}
