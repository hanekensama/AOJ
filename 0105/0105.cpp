#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  map<string, vector<int> > index;
  string str;
  int page;
  while(cin >> str >> page) index[str].push_back(page);

  for (auto i : index) {
    cout << i.first << endl;
    sort(i.second.begin(), i.second.end());
    for (auto j : i.second) cout << j << " ";
    cout << endl;
  }
}
