#include "powerSetParams.h"
#include "powerSetReturn.h"
#include "powerSetBacktracking.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

//O(2^n*n) time: 2^n combinations, each combination is copied in O(n)
//O(2^n*n) space: space necessary to store all the combinations

int main(int argc, char**argv) {
  std::vector<char> items{ 'a','b','c','d' };

  auto powerSet = powerSetParams(items);
  auto samePowerSet = powerSetReturn(items);
  auto samePowerSetB = powerSetBacktracking(items);

  std::sort(powerSet.begin(),powerSet.end());
  std::sort(samePowerSet.begin(),samePowerSet.end());

  if (!std::equal(powerSet.begin(), powerSet.end(), samePowerSet.begin())) {
    throw std::runtime_error("powerSetParams different from powerSetReturn");
  }

  for (auto set : samePowerSet) {
    for (auto item : set) {
      std::cout << item << " ";
    }
    std::cout << "\n";
  }
}
