#include <bits/stdc++.h>
using namespace std;


int solve(int A, int B, int C, vector<int>& cal) {
  sort(cal.begin(), cal.end(), greater<int>());

  auto c = C;
  double result = c / A;

  for (auto i = 0; i < cal.size(); ++i) {
    c += cal[i];
    auto p = A + B * (i + 1);
    double next = max(result, (double)c / p);
    if (next < result) break;
    
    result = next;
  }

  return (int)result;
}

int main() {
  int N, A, B, C;
  cin >> N;
  cin >> A >> B;
  cin >> C;
  vector<int> cal(N);
  for (auto i = 0; i < N; ++i) {
    cin >> cal[i];
  }

  cout << solve(A, B, C, cal) << endl; 
}
