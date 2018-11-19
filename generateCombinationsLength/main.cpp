#include "powerSetParams.h"
#include "powerSetReturn.h"
#include <iostream>
#include <vector>
#include <stdexcept>

//O(2^n*n) time: 2^n combinations, each combination is copied in O(n)
//O(2^n*n) space: space necessary to store all the combinations

int main(int argc, char**argv) {
  std::vector<char> items{ 'a','b','c','d' };
  
  auto powerSet = powerSetParams(items,2);
  auto samePowerSet = powerSetReturn(items,2);

  if (!std::equal(powerSet.begin(), powerSet.end(), samePowerSet.begin())) {
    throw std::runtime_error("powerSetParams different from powerSetReturn");
  }
  
  for (auto set : powerSet) {    
    for (auto item : set) {
      std::cout << item << " ";
    }
    std::cout << "\n";
  }
}
