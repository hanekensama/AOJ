#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& v1, vector<int>& v2) {
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());

  int sum1 = accumulate(v1.begin(), v1.end(), 0);
  int sum2 = accumulate(v2.begin(), v2.end(), 0);
  int diff = sum2 - sum1;

  if (diff % 2 == 0) {
    diff /= -2;
    for (auto i = 0; i < v1.size(); i++) {
      for (auto j = 0; j < v2.size(); j++) {
	if (v1[i] - v2[j] == diff) {
	  cout << v1[i] << " " << v2[j] << endl;
	  return 0;
	}
      }
    }
  }
  cout << -1 << endl;
  return 1;
}

int main() {
  int n, m;
  while(cin >> n >> m, n | m) {
    vector<int> taro(n), hanako(m);
    int s;
    for (int i = 0; i < n; i++) {
      cin >> taro[i];
    }
    
    for (int i = 0; i < m; i++) {
      cin >> hanako[i];
    }

    solve(taro, hanako);
  }

  return 0;
}
