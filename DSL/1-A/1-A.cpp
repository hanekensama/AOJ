#include <bits/stdc++.h>
using namespace std;

class UnionFindTree {
private:
  vector<int> data;
  
  auto root(int x) -> int {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }

  auto size(int x) -> int {
    return -data[root(x)];
  }
  
public:
  UnionFindTree(int size) : data(size, -1) {}
  
  auto uniteTree(int x, int y) -> bool {
    x = root(x);
    y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y];
      data[y] = x;
    }

    return x != y;
  }
  
  auto isSameTree(int x, int y) -> bool {
    return root(x) == root(y);
  }
};

int main() {
  int n, q;

  cin >> n >> q;
  UnionFindTree ufTree = UnionFindTree(n);

  for (int i = 0; i < q; ++i) {
    int c, x, y;
    cin >> c >> x >> y;
    if (c == 0) ufTree.uniteTree(x, y);
    else        cout << (ufTree.isSameTree(x, y) ? 1 : 0) << endl;
  }

  return 0;
}
