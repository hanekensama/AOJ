#include <bits/stdc++.h>
#define MIN -100000
using namespace std;

int solve(const vector<int>& v,int k) {
  int mx = MIN;
  int i = 0;
  auto begin = v.begin();
  while(i++ < v.size() - k) {
    mx = max(mx, accumulate(begin, begin + k, 0));
    begin++;
  }

  return mx;
}

int main() {
  int n, k;
  while (cin >> n >> k, n | k) {
    vector<int> v(n);
    for(auto i = 0; i < n; i++) cin >> v[i];

    cout << solve(v, k) << endl;
  }
  return 0;
}
