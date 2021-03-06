#include <bits/stdc++.h>
using namespace std;

class RMQ {
private:
  vector<int> v;
  
public:
  RMQ(int size) {
    v = vector<int>(size, INT_MAX);
  }

  auto update(int i, int x) -> void {
    v[i] = x;
  }
  
  auto find(int s, int t) -> int {
    return *min_element(v.begin() + s, v.begin() + t);
  }
};

int main() {
  int n, q;
  cin >> n >> q;
  RMQ rmq = RMQ(n);

  for (int i = 0; i < q; ++i) {
    int c, x, y;
    cin >> c >> x >> y;
    if (c == 0) rmq.update(x, y);
    else        cout << rmq.find(x, y) << endl;
  }

  return 0;
}
