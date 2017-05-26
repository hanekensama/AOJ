#include <bits/stdc++.h>
using namespace std;

class Base {
private:
  int runner;

public:
  Base() : runner(0) {}
  int hit() {
    int point = (runner & 4) >> 2;
    runner <<= 1;
    runner |= 1;
    return point;
  }
  int homerun() {
    int point = 1;
    for (int i = 0; i <3; ++i) {
      point += (runner >> i) & 1;
    }
    runner <<= 3;
    return point;
  }
};

void solve(int n) {
  for (int i = 0; i < n; ++i) {
    int point = 0;
    int out = 0;
    Base base = Base();

    while(out < 3) {
      string s;
      cin >> s;
      if (s == "HIT")          point += base.hit();
      else if (s == "HOMERUN") point += base.homerun();
      else                     out++;
    }
    cout << point << endl;
  }

}

int main() {
  int n;
  cin >> n;
  solve(n);
}
