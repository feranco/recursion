#include <vector>
#include "countUniqueBSTs.h"
#include <iostream>
using std::vector;

int countUniqueBst(vector<int> values, int k) {

  if (values.size() == 0) return 1;
  if (values.size() == 1) return 1;
  
  int cnt = 0;
  int j = 0;
  for (auto it = values.begin(); it != values.end(); ++it) {
    cnt += countUniqueBst(vector<int>(values.begin(), it), k+1) * countUniqueBst(vector<int>(next(it), values.end()),k+1);
    if (k == 0) std::cout << j++ << " " << cnt << "\n";
  }
  
  return cnt;
}

int countUniqueBst(int n) {
  vector<int> values(n);
  for (int i = 1; i <= n; ++i) values[i-1] = i;
  std::cout << values.size() << "\n";
  return countUniqueBst(values, 0);
}

