#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<pair<int, int> > > Logs

void getLogs(Logs& log) {
  vector<int> flag(log.size());
  int r;
  cin >> r;
  for (int i = 0; i < r; i++) {
    int t, n, m, s;
    cin >> t >> n >> m >> s;
    if (s == 1 && ++flag[m] == 1) log[m].push_back(make_pair(t, 0));
    else if (s == 0 && --flag[m] == 0) log[m].back.second = t; 
  }
}

int checkLog(const Logs& log, int m, int ts, int te) {
  int time = 0;
  for (auto login : log[m]) {
    if (te < login.first) break;
    else if (ts <= login.second && te >= login.first)
      time += min(te, login.second) - max(ts, login.second);
  }
  return time;
}

int main() {
  int N, M;
  
  return 0;
}
