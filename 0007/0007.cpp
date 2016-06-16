#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int money = 100000;
  for (int i = 0; i < n; i++) {
    money *= 1.05;
    if (money % 1000 != 0) money = ((money / 1000) + 1) * 1000;
  }
  cout << money << endl;
  return 0;
}
