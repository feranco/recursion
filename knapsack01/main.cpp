#include "knapsack01.h"
#include "knapsack01Dfs.h"
#include <iostream>

int main () {

  std::vector<Item> items {{1,1}, {2,2}, {2,3}, {2,4}, {2,5}};
  
  auto resultParams = knapsack01Params(items, 7);
  auto resultReturn = knapsack01Return(items, 7);
  if (!std::equal(resultParams.items.begin(), resultParams.items.end(), resultReturn.items.rbegin()) ||
      resultParams.value != resultReturn.value) {
    throw std::runtime_error("resultParams different from resultReturn");
  }
  
  std::cout << "Max Value: " << resultParams.value << "\n";
  std::cout << "Items: ";
  for (auto idx : resultParams.items) {
    std::cout << idx << " ";
  }

  auto resultDfs = knapsack01Dfs(items, 7);
  std::cout << "Max Value Dfs: " << resultDfs.value << "\n";
  std::cout << "Items Dfs: ";
  for (auto idx : resultDfs.items) {
    std::cout << idx << " ";
  }
}
