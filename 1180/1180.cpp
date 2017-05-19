#include <bits/stdc++.h>
using namespace std;

int VtoI(const vector<int>& v) {
  int num = 0;
  for (auto i : v) {
    num *= 10;
    num += i;
  }
  return num;
}

void ItoV(int num, int n, vector<int>& v) {
  v = vector<int> (n);
  int i = n - 1;
  while(i >= 0) {
    v[i] = num % 10;
    num /= 10;
    i--;
  }
}

int next(int i, int n) {
  vector<int> v;
  ItoV(i, n, v);
  sort(v.begin(), v.end());
  auto min = VtoI(v);
  reverse(v.begin(), v.end());
  auto max = VtoI(v);
  return max - min;
}

void solve(int a,int n) {
  map<int, int> mp;
  int i = 0;
  while(true) {
    if (mp.find(a) != mp.end()) {
      break;
    }
    
    mp[a] = i;
    a = next(a, n);
    i++;
  }

  cout << mp[a] << " " << a << " " << i - mp[a] << endl;
  return;
}

int main() {
  int a, n;
  while(cin >> a >> n, a | n) {
    solve(a, n);
  }

  return 0;
}
