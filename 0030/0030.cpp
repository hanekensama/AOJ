#include <bits/stdc++.h>
using namespace std;

int dfs(int n, int s, int i) {
  if (n == 0 && s == 0) return 1;
  if (n == 0 || s == 0) return 0;
  if ((n == 1) && (s <= i)) return 1;
  int ans = 0;
  while(i > 0) {
    if (i < s) ans += dfs(n - 1, s - i, i - 1);
    i--;
  }
}

int main() {
  int n, s;
  while(cin >> n >> s, n != 0) {
    cout << dfs(n, s, 9) << endl;
  }
}
