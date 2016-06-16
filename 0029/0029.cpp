#include <bits/stdc++.h>
using namespace std;

int main() {
  map<string, int> words;
  string input, word_l, word_f;
  int length, freq;
  while(cin >> input) {
    words[input]++;
    if (words[input] > freq) {
      word_f = input;
      freq = words[input];
    }
    if (input.size() > length) {
      word_l = input;
      length = input.size();
    }
  }
  cout << word_f << " " << word_l << endl;
  return 0;
}
