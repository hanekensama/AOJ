#include <bits/stdc++.h>
using namespace std;

#define N 1000001
int dp[N], dp_o[N];

int main(void) {
  for (int i = 0; i < N; i++) {
    dp[i] = i;
    dp_o[i] = i;
  }
  
  for (int i = 2; i < N; i++) {
    int p = i * (i + 1) * (i + 2) / 6;
    if (p > N) break;
    for (int j = 0; j < N - p; j++)
      dp[j+p] = min(dp[j+p], dp[j] + 1);
    if(p % 2 == 1) {
      for(int j = 0; j < N - p; j++) 
	dp_o[j + p] = min(dp_o[j + p], dp_o[j] + 1);
    }
  }

  int n;
  while(cin >> n, n) {
    cout << dp[n] << " " << dp_o[n] << endl;
  }
  return 0;
}

