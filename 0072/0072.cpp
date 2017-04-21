#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

int solve(int n, int m, const vector<vector<int> > edges) {
  priority_queue<PII, vector<PII>, greater<PII> > pq;
  vector<bool> visited(n, false);

  int sum = 0;
  pq.push(make_pair(0, 0));
  
  while(!pq.empty()) {
    auto top = pq.top(); pq.pop();
    auto node = top.second;
    if (!visited[node]) {
      visited[node] = true;
      sum += top.first;
      
      for (auto i = 0; i < n; i++) {
	auto cost = edges[node][i];
	if (cost > 0) pq.push(make_pair(cost, i));
      }
    }
  }
  
  return sum;
}

int main() {
  int n;
  while(cin >> n, n) {
    int m;
    cin >> m;

    vector<vector<int> > street(n, vector<int>(n));

    for (auto i = 0; i < m; i++) {
      int a, b, d;
      scanf("\n%d,%d,%d", &a, &b, &d);
      d /= 100;
      d -= 1;
      street[a][b] = d;
      street[b][a] = d; 
    }

    cout << solve(n, m, street) << endl;
  }
  return 0;
}
