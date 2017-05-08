#include <bits/stdc++.h>
using namespace std;

bool checkAndPop(stack<char>& stk, char c) {
  if (stk.empty()) return false; 
  if ( (c == ')') && (stk.top() != '(') ) return false;
  if ( (c == ']') && (stk.top() != '[') ) return false;

  stk.pop();
  return true;
}

bool solve(const std::string& s) {
  stack<char> stk;
  for (auto c : s) {
    switch (c) {
    case '(':
    case '[':
      stk.push(c);
      break;
      
    case ')':
    case ']':
      if (!checkAndPop(stk, c)) return false;
      break;
    }
  }
  return stk.empty();
}

int main() {
  string s;
  while(getline(cin, s), s.size() > 1) {
    if (solve(s)) cout << "yes" << endl;
    else          cout << "no"  << endl;
  }
  return 0;
}
