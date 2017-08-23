#include <bits/stdc++.h>
using namespace std;

int n;
vector<set<int> > f;

int solve() {
  vector<long> have(n, 0);
  for (int i = 0; i < n; ++i) {
    have[i] |= ((long)1 << i);
  }

  for (int i = 1; i <= 30; ++i) {
    long flag = 0;
    for(int j = 0; j < n; ++j) {
      if (f[j].find(i) != f[j].end())
	flag |= have[j];
    }

    for (int j = 0; j < n; ++j) {
      if (f[j].find(i) != f[j].end()) {
	have[j] |= flag;
	if (have[j] == ((long)1 << n) - 1) return i;
      }
    }
  }
  return -1;
}

int main() {
  while(cin >> n, n) {
    f = vector<set<int> > (n);
    for (int i = 0; i < n; ++i) {
      int g;
      cin >> g;
      for (int j = 0; j < g; ++j) {
	int val;
	cin >> val;
	f[i].insert(val);
      }
    }
    cout << solve() << endl;
  }
  return 0;
}
