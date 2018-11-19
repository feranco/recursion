#include <list>
#include <vector>

#pragma once

template <typename T>
using Set = std::list<T>;
template <typename T>
using PowerSet = std::vector<Set<T>>;

template <typename T>
void generatePowerSet (const std::vector<T>& items, unsigned int i, PowerSet<T>& result, Set<T> currentSet) {
  
  if (i == items.size()) {
    result.emplace_back(currentSet);
    return;
  }

  generatePowerSet(items, i+1, result, currentSet);
  Set<T> withCurrentItem = currentSet;
  withCurrentItem.emplace_back(items[i]);
  generatePowerSet(items, i+1, result, withCurrentItem);
}

template <typename T>
PowerSet<T> powerSetParams (const std::vector<T>& items) {
  PowerSet<T> result;
  generatePowerSet(items, 0, result, Set<T>());
  return result;
}




