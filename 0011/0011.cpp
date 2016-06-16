#include <bits/stdc++.h>
using namespace std;

int main() {
  int w, n;
  vector<int> l;
  cin >> w; cin >> n;
  for (int i = 0; i < w; i++) l.push_back(i + 1);
  for (int i = 0; i < n; i++) {
    int a, b; char comma;
    cin >> a >> comma >> b; a--; b--;
    int buf = l[a]; l[a] = l[b]; l[b] = buf;
  }
  for (int i = 0; i < w; i++) cout << l[i] << endl;
  return 0;
}
