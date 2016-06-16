#include <bits/stdc++.h>
using namespace std;

int main() {
  string input;
  cin >> input;

  auto it = input.end();
  while(it != input.begin()) cout << *(--it);
  cout << endl;
  return 0;
}
