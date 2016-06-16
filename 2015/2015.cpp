#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, buf;
  
  while(true) {
    cin >> N >> M;
    if (N == 0) break;
    vector<int> h,w;
    h.push_back(0); w.push_back(0);
    for (int i = 0; i < N; i++) { cin >> buf; h.push_back(h.back() + buf); }
    for (int i = 0; i < M; i++) { cin >> buf; w.push_back(w.back() + buf); }
 
    int h_n[1500001], w_n[1500001];
    for(int i = 0; i < N; i++) {
      for(int j = i + 1; j <= N; j++) {
	h_n[h[j] - h[i]]++;
      }
    }
    for (int i = 0; i < M; i++) {
      for(int j = i + 1; j <= M; j++) {
	w_n[w[j] - w[i]]++;
      }
    }
    int cnt = 0;
    for(int i = 0; i <= 1500000; i++) {
      cnt += h_n[i] * w_n[i];
    }
    cout << cnt << endl;
  }
  return 0;
}
