#include <bits/stdc++.h>
using namespace std;

double dist(vector<double> a, double ra, vector<double> b, double rb) {
  double dx = a[0] - b[0];
  double dy = a[1] - b[1];
  double dz = a[2] - b[2];
  return max(0.0, sqrt(dx * dx + dy * dy + dz * dz) - (ra + rb));
}

int main() {
  int n;
  while(cin >> n, n != 0) {
    vector<vector<double> > a(n);
    vector<double> r(n);
    bitset<100> flag;
    for (int i = 0; i < n; i++) {
      a[n] = vector<double> (3);
      cin >> a[i][0] >> a[i][1] >> a[i][2] >> r[i];
    }
    
    double cost = 0.0;
    int i , used = 1;
    vector<double> dists(n);
    for (int i = 0; i < n; i++) {
      dists[i] = dist(a[0], r[0], a[i], r[i]);
    }
    
    while(used < n) {
      i = 1;
      
    }
    cout << cost << endl;
  }
  return 0;
}
