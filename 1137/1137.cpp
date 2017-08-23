#include <bits/stdc++.h>
using namespace std;

map<char, int> dict;

void init() {
  dict = map<char, int>();
  dict['m'] = 1000;
  dict['c'] = 100;
  dict['x'] = 10;
  dict['i'] = 1;
  
}

int MCXItoInt(string mcxi) {
  int num = 0;
  int i = 1;
  for (auto c : mcxi) {
    if (isdigit(c)) i = atoi(&c);
    else {
      num += dict[c] * i;
      i = 1;
    }
  }

  return num;
}

string InttoMCXI(int num) {
  string mcxi;
  char chars[] = {'m', 'c', 'x', 'i'};
  int div = 1000;
  
  for (int i = 0; i < 4; ++i) {
    auto f = (num / div) % 10;
    if (f > 1) mcxi += to_string(f) + chars[i];
    else if (f == 1) mcxi += chars[i];
    div /= 10;
  }

  return mcxi;
}

string solve(string s1, string s2) {
  auto n1 = MCXItoInt(s1);
  auto n2 = MCXItoInt(s2);
  return InttoMCXI(n1 + n2);
}

int main() {
  init();

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s1, s2;
    cin >> s1 >> s2;
    cout << solve(s1, s2) << endl;
  }
  
  return 0;
}