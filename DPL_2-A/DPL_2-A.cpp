#include <bits/stdc++.h>
using namespace std;

int add(int l, int r) {
  if(l == INT_MAX || r == INT_MAX) return INT_MAX;
  else return r + l;
}

int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<int> > dist(V, vector<int> (V, INT_MAX));
  vector<vector<int> > dp((1 << V) - 1, vector<int> (V, INT_MAX));
  dp.push_back(vector<int> (V, 0));
  
  for (int i = 0; i < E; i++) {
    int s, t, d;
    cin >> s >> t >> d;
    dist[s][t] = d;
  }

  for (int s = (1 << V) - 1; s >= 0; s--) {
    for (int c = 0; c < V; c++) {
      for (int n = 0; n < V; n++) {
	if ((s & 1 << n) == 0)
	  dp[s][c] = min(dp[s][c], add(dp[s | 1 << n][n], dist[c][n]));
      }
    }    
  }
  if (dp[0][0] == INT_MAX) cout << -1 << endl;
  else cout << dp[0][0] << endl;

  return 0;
}
