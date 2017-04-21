#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m, const vector<vector<int> >& edges) {
  auto comp = [](pair<int, int> a, pair<int, int> b) {return a < b;};
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > p_que;
  vector<bool> visited(n, false);

  int cost = 0;
  p_que.push(make_pair(0, 0));

  while(!p_que.empty()) {
    auto top = p_que.top(); p_que.pop();
    int node = top.second;
    if (!visited[node]) {
      visited[node] = true;
      cost += top.first;

      for (auto i = 0; i < n; ++i) {
	int c = edges[node][i];
	if (c > 0) p_que.push(make_pair(c, i));
      }
    }
  }
  
  return cost;
}

int main() {
  int n, m;
  while (cin >> n >> m, n | m) {
    vector<vector<int> > edges(n, vector<int>(n));
    for (auto i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      edges[a][b] = c;
      edges[b][a] = c;
    }
    cout << solve(n, m, edges) << endl; 
  }

  return 0;
}
