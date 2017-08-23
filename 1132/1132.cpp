#include <bits/stdc++.h>
#define EPS (1e-10)
using namespace  std;

typedef complex<double> V;

int n;
vector<V> points;

pair<V, V> circles(const V& a, const V& b) {
  V v = a - b;
  double dist = abs(v);
  V n1 = (v * V(0, 1)) / dist;
  V n2 = (v * V(0, -1)) / dist;

  dist /= 2;
  double x = sqrt(1 - (dist * dist));

  return make_pair((b + v / 2.) + x * n1, (b + v / 2.) + x * n2);
}

int countInCircle(const V& center) {
  int count = 0;
  for (auto p : points) {
    if (abs(p - center) < 1 + EPS) count++;
  }
  return count;
}

int solve() {
  int count = 1;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (abs(points[i] - points[j]) < 2 + EPS) {
	auto c = circles(points[i] , points[j]);
	count = max(count, countInCircle(c.first));
	count = max(count, countInCircle(c.second));
      }
    }
  }
  return count;
}

int main() {
  while(cin >> n, n) {
    points = vector<V>(n);
    for (int i = 0; i < n; ++i) {
      double x, y;
      cin >> x >> y;
      points[i] = V(x, y);
    }

    cout << solve() << endl;
  }
  return 0;
}
