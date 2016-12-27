#include<bits/stdc++.h>
using namespace std;

int x, y, z;
vector<int> v;
vector<pair<int, int> > map;

auto solve(int current=0) -> double {
  
}

auto main() -> int {
  while(true) {
    cin >> x >> y >> z;
    if (x == 0) break;

    v = vector<int>(x);
    for (int i = 0; i < x; i++) cin >> v[i];

    map = vector<pair<int, int> >(y + 1, make_pair(0, 0));
    for (int i = 0; i < z; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      map[a] = make_pair(b, c);
    }

    cout < solve();
  }
}
