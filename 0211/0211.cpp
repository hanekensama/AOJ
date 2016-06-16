#include <bits/stdc++.h>
using namespace std;

bool Goal(const vector<double> &t, const vector<int> &r) {
  double t_max = t[0] * r[0];
  for (int i = 1; i < t.size(); i++) {
    if (t[i] * r[i] != t_max) return false;
  }
  return true;
}

int main() {
  int end, n, d, v;
  vector<double> t;
  while(true) {
    cin >> n;
    if (n == 0) break;
    for (int i = 0; i < n; i++) {
      cin >> d >> v;
      t.push_back((double)d / (double)v);
    }
  
    vector<int> round(n, 1);
    double t_max = t[0] * round[0];
    for (int i = 0; i < n; i++) {
      double t_ = t[i] * round[i];
      while(t_ < t_max) {
	round[i]++;
	t_ += t[i];
      }
      if (t_ > t_max) {
	t_max = t_;
	i = 0;
      }
    }
  
    for (auto r : round) {
      cout << r << endl;
    }
  }
  
  return 0;
}
