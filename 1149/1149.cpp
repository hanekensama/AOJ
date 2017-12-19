#include <bits/stdc++.h>
using namespace std;

typedef struct Cake
{
  int w;
  int d;
  Cake(int w=0, int d=0) : w(w), d(d) {};
  int size() { return (w * d);}
  pair<Cake, Cake> cut(int s) {
    s %= 2 * (w + d);

    pair<Cake, Cake> cutten;
    if (s < w) {
      cutten = make_pair(Cake(s, d), Cake(w - s, d));
    } else if ((s -= w) < d) {
      cutten = make_pair(Cake(w, s), Cake(w, d - s));
    } else if ((s -= d) < w) {
      cutten = make_pair(Cake(s, d), Cake(w - s, d));
    } else {
      s -= w;
      cutten = make_pair(Cake(w, s), Cake(w, d - s));
    }

    if (cutten.first.size() > cutten.second.size()) 
      swap(cutten.first, cutten.second);

    return cutten;
  } 
}Cake_t;

void solve(int n, int w, int d) {
  vector<Cake> cakes;
  cakes.push_back(Cake(w, d));

  for (int i = 0; i < n; ++i) {
    int p, s;
    cin >> p >> s;
    auto cutten = cakes[p - 1].cut(s);
    cakes.erase(cakes.begin() + p - 1);
    cakes.push_back(cutten.first);
    cakes.push_back(cutten.second);
  }

  sort(cakes.begin(), cakes.end(), 
       [](Cake a, Cake b) {return a.size() < b.size();});
  
  cout << cakes[0].size();
  for (auto i = 1; i < cakes.size(); ++i) {
    cout << " " << cakes[i].size();
  }
  cout << endl;
}

int main() {
  int n, w, d;
  while( cin >> n >> w >> d, n | w | d) {
    solve(n, w, d);
  }
  return 0;
}
