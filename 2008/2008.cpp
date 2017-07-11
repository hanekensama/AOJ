#include <bits/stdc++.h>
#define EPS (1e-10)
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

using namespace std;
typedef pair<int, int> PII;

int n, hx, hy, dx, dy;
int cx[20], cy[20];

bool solve(int x, int y, double t, int unvisit) {
  cerr << "hero(" << x << "," << y <<"), t=" << t << ",flag=" << bitset<20>(unvisit) << endl;
  
  if (unvisit == 0) return true;

  REP(i, n) {
    if ((unvisit >> i) & 1)
      if (t + hypot(x - cx[i], y - cy[i]) >= hypot(dx - cx[i], dy - cy[i])+ EPS) return false;
  }

  REP(i, n) {
    if ((unvisit >> i) & 1) {
      if (solve(cx[i], cy[i], t + hypot(x - cx[i], y - cy[i]),
		unvisit ^ (1 << i))) return true;
    }
  }
  return false;
}

int main() {
  while (cin >> n >> hx >> hy >> dx >> dy, n | hx | hy | dx | dy) {
    REP(i, n) {
      cin >> cx[i] >> cy[i];
    }
    cout << (solve(hx, hy, 0., (1 << n) -1) ? "YES" : "NO") << endl;
  }
  return 0;
}
