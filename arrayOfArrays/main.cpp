#include "arrayOfArrays.h"
#include <iostream>

int main () {
  vector<vector<int>> arr2D{{1,2}, {3}, {4,5}};
  auto result = arrayOfArrays(arr2D);
  for (const auto& arr : result) {
    for (int x : arr) {
      std::cout << x << " ";
    }
    std::cout << "\n";
  }
}


