#include <bits/stdc++.h>
using namespace std;
#define INF 1000000
#define PII pair<int, int>
#define VPII vector<pair<int,int> >

int dijkstra(int n, const vector<vector<int> >& edge, int s, int g) {
  vector<bool> used(n, false);
  vector<int> dist(n, INF);
  dist[s] = 0;
  priority_queue<PII, VPII, greater<PII > >q;
  q.push(make_pair(0, s));
  while(q.size() > 0) {
    PII v = q.top(); q.pop();
    int current = v.second;
    used[current] = true;
    for (int i = 0; i < n; i++) {
      if (edge[current][i] != INF) {
	dist[i] = min(dist[i], dist[current] + edge[current][i]);
	if (!used[i]) {
	  q.push(make_pair(dist[i], i));
	}
      }
    }
  }
  return dist[g];
}

int main() {
  int n, m;
  cin >> n;
  cin >> m;
  vector<vector<int> > edge(n, vector<int>(n, INF));
  for (int i = 0; i < m; i++) {
    int a, b, c, d;
    scanf("%d,%d,%d,%d\n", &a, &b, &c, &d);
    a--; b--;
    edge[a][b] = c;
    edge[b][a] = d;
  }
  int s, g, V, P;
  scanf("%d,%d,%d,%d\n", &s, &g, &V, &P);
  s--; g--;
  int outward = dijkstra(n, edge, s, g);
  int homeward = dijkstra(n, edge, g, s);
  cout << V - P - outward - homeward << endl;
}
