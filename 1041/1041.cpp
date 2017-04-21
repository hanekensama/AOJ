#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
  int shoot = n / 4;

  int sum = 0;
  for (auto i = 0; i < shoot; ++i) {
    int num;
    cin >> num;
    sum += num;
  }

  return sum;
}

int main() {
  int n;
  
  while(cin >> n, n)
    cout << solve(n) << endl;
  
  return 0;
}
