#include <stack>
#include <iostream>

using namespace std;

int main() {
  stack<int> s;

  int i;
  while(cin >> i) {
    if (i != 0) s.push(i);
    else {
      cout << s.top() << endl;
      s.pop();
    }
  }
}
