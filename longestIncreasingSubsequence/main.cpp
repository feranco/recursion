#include "longestIncreasingSubsequence.h"
#include <iostream>

int main() {
  //list<int> sequence{0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
  list<int> sequence{9,6,1,5,3,7,55,12};
  auto result = longestIncreasingSubsequence(sequence);
  for (int x : result) std::cout << x << " ";
}
