#include <bits/stdc++.h>
using namespace std;

bool isOK(string worm) {
  for (int i = 1; i < worm.size(); i++) if (worm[0] != worm[i]) return false;
  return true;
}

char newColor(char a, char b) {
  if (a > b) swap(a, b);
  if (a == 'b' && b == 'g') return 'r';
  else if (a == 'b' && b == 'r') return 'g';
  else return 'b';
}

int solve(string worm) {
  queue<pair<string, int> > open;
  map<string, int> close;

  open.push(make_pair(worm,0));
  close.insert(make_pair(worm, 1));

  while(!open.empty()) {
    pair<string, int> w = open.front();
    open.pop();

    if (isOK(w.first)) return w.second;

    for (int i = 0; i < w.first.size() - 1; i++) {
      if (w.first[i] != w.first[i + 1]) {
	string tmp = w.first;

	char new_color = newColor(w.first[i], w.first[i + 1]);
	tmp[i] = new_color;
	tmp[i + 1] = new_color;

	if (close[tmp]) continue;
	open.push(make_pair(tmp, w.second+1));
	close[tmp] = 1;
      }
    }
  }

  return -1;
}

int main() {
  string worm;
  while (cin >> worm, worm != "0") {
    if (int result = solve(worm) != -1) cout << result << endl;
    else cout << "NA" << endl;
  }

  return 0;
}
