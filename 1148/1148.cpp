#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  while(cin >> N >> M, N && M) {
    int r;
    cin >> r;
    vector<vector<int> > log(M + 1);
    vector<int> flag(M + 1,0);
    for (int i = 0; i < r; i++) {
      int t, n, m, s;
      cin >> t >> n >> m >> s;
      if(s == 1) {
	flag[m]++;
	if(flag[m] == 1) log[m].push_back(t);
      }
      else {
	flag[m]--;
	if(flag[m] == 0) log[m].push_back(t);
      }
    }
    int q;
    cin >> q; 
    for (int i = 0; i < q; i++) {
      int ts, te, qm;
      cin >> ts >> te >> qm;
      int t = 0;
      for(int i = 0; i < log[qm].size(); i += 2) {
	if (te < log[qm][i]) break;
	else if (ts <= log[qm][i + 1] && te >= log[qm][i]) {
	  t += min(te, log[qm][i + 1]) - max(ts, log[qm][i]);
	}
      }
      cout << t << endl;
    }
  }

  return 0;
}
