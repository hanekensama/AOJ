#include <bits/stdc++.h>
using namespace std;

auto solve(int n) -> long {
  vector<int> dp(n + 1, 1);

  dp[2] = 2;
  for (int i = 3; i <= n; i++) 
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
  
  return dp[n];  
}

auto main() -> int {
  int n;
  while(cin >> n, n != 0) {
    auto days = (int)ceil((double)solve(n) / 10);
    auto years = (int)ceil((double)days / 365);
    std::cout << years << std::endl;
  }
  return 0;
}
