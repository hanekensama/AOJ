#include <bits/stdc++.h>
using namespace std;
#define MAX_INT 10000
#define PII pair<int, int>
#define VPII vector<PII >

int solve(int n, const vector<VPII >& adjacent) {
  vector<bool> used(n, false);
  int result = 0;
  priority_queue<PII, VPII, greater<PII > > q;
  for (auto v : adjacent[0]) q.push(v);
  used[0] = true;
  while(q.size() > 0) {
    PII current = q.top(); q.pop();
    if (!used[current.second]) {
      used[current.second] = true;
      result += current.first;
      for (auto v : adjacent[current.second]) q.push(v);
    }
  }

  return result;
}

int main() {
  int n, m;
  while (cin >> n >> m, n != 0) {
    vector<VPII > adjacent(n);
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      adjacent[a].push_back(make_pair(c, b));
      adjacent[b].push_back(make_pair(c, a));
    }
    cout << solve(n, adjacent) << endl;
  }
}
