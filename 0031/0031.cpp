#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
  string str;
  for (int i = 0; i < 10; i++)
    if ((n >> i) & 1)
      str += to_string(1 << i) + " ";

  if (!str.empty())
    str.pop_back();

  cout << str << endl;
}

int main() {
  int n;
  while (cin >> n)
    solve(n);

  return 0;
}
