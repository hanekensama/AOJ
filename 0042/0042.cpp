#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

int N;
int W;
vector<int> vv;
vector<int> vw;

PII solve() {
  vector<vector<int> > dp(N+1, vector<int> (W+1, 0));

  for (int i = N - 1; i >= 0; i--) {
    for (int w = 0; w <= W; w++) {
      if (w < vw[i])
	dp[i][w] = dp[i + 1][w];
      else
	dp[i][w] = max(dp[i + 1][w],
		       dp[i + 1][w - vw[i]] + vv[i]);
    }
  }

  auto v_max = dp[0][W];
  auto w_min = W;
  for (int i = 0; i < W; i++) {
    if (dp[0][i] == v_max) {
      w_min = i;
      break;
    }
  }
  
  return make_pair(v_max, w_min);
}

int main() {
  int c = 1;
  while (true) {
    cin >> W;
    if (W == 0) break;
    
    vv.clear();
    vw.clear();
    cin >> N;
    vv.resize(N);
    vw.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("\n%d,%d", &vv[i], &vw[i]);
    }

    cout << "Case " << c++ << ":" << endl;
    auto result = solve();
    cout << result.first << endl << result.second << endl;
  }
}
