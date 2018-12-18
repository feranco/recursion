#include "partitionEqualSumSubset.h"
#include <iostream>

int main() {
  vector<int> p{4,3,2,3,5,2,1};
  auto res = canPartitionKSubsets(p, 4);
  std::cout << res;
}
