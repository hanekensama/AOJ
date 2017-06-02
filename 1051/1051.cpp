#include <bits/stdc++.h>
using namespace std;

string cont(const vector<int>& v, int& i) {
  int begin = v[i];
  int pre = v[i];

  while(++i < v.size() & v[i] == pre + 1)
    pre = v[i];

  if (begin == pre)
    return to_string(begin);
  else
    return to_string(begin) + "-" + to_string(v[i - 1]);
}

void solve(const vector<int>& v) {
  string result;
  int i = 0;
  cout << cont(v, i);
  while(i < v.size()) {
    cout << " " << cont(v, i);
  }
  cout << endl;
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
