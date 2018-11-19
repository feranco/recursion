#include <list>
#include <vector>

#pragma once

template <typename T>
using Set = std::list<T>;
template <typename T>
using PowerSet = std::vector<Set<T>>;

/*
enum Candidates {
  Exclude = 0,
  Include = 1,
  Last
};
*/

template <typename T>
void generatePowerSet (const std::vector<T>& items, unsigned int i, PowerSet<T>& result, std::vector<int>& isInPowerSet) {
  
  if (i == items.size()) {
    Set<T> currentSet;
    for (unsigned int j = 0; j < items.size(); ++j) {
      if (isInPowerSet[j]) currentSet.emplace_back(items[j]);
    }
    result.emplace_back(currentSet);
    return;
  }

  std::vector<int> candidates{0,1};
  for (unsigned int j = 0; j < candidates.size(); ++j) {
    isInPowerSet[i] = candidates[j];
    generatePowerSet(items, i+1, result, isInPowerSet);
  }
}

template <typename T>
PowerSet<T> powerSetBacktracking (const std::vector<T>& items) {
  PowerSet<T> result;
  std::vector<int> isInPowerSet(items.size(),0);
  generatePowerSet(items, 0, result, isInPowerSet);
  return result;
}
