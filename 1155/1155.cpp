#include <bits/stdc++.h>
using namespace std;

int P, Q, R;

int formula(string& f, int& i) {
  switch(f[i++]) {
  case '-' : return 2 - formula(f, i);
  case 'P' : return P;
  case 'Q' : return Q;
  case 'R' : return R;
  case '0' : return 0;
  case '1' : return 1;
  case '2' : return 2;
  case '(' :
    int f1 = formula(f, i);
    int f2;
    switch(f[i++]) {
    case '*' :
      f2 = formula(f, i);
      i++;
      return min(f1, f2);
    case '+' :
      f2 = formula(f, i);
      i++;
      return max(f1, f2);
    }
  }
   
  return 0;
}

int main() {
  string f;
  while(cin >> f, f[0] != '.') {
    int cnt = 0;
    for (P = 0; P <= 2; P++) {
      for (Q = 0; Q <= 2; Q++) {
    for (R = 0; R <= 2; R++) {
      int i = 0;
      if(formula(f, i) == 2) cnt++;
    }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
