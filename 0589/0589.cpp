#include <bits/stdc++.h>
using namespace std;

bool comparator(const string& a, const string& b) {
  if (a.size() == b.size()) return a < b;
  else                      return a.size() < b.size();
}

int solve(int n) {
  map<string, int, decltype(comparator)*> orders(comparator);
  //map<string, int, bool(*)(const string&, const string&)> orders(comparator);

  for (auto i = 0; i < n; ++i) {
    string name;
    int num;
    cin >> name >> num;
    orders[name] += num;
  }

  for (auto order : orders) {
    cout << order.first << " " << order.second << endl;
  }

}

int main() {
  int n;
  cin >> n;
  solve(n);
  return 0;
}
