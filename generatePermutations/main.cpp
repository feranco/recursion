#include "generatePermutations.h"
#include <iostream>

int main () {
  unordered_set<char> items{'a','b','c','d'};
  auto res = generatePermutations (items);
  for (const auto& p : res) {
    for (const auto& c : p) {
      std::cout << c << " ";
    }
    std::cout << "\n";
  }
}





