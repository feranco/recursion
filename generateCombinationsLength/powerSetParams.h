#include <list>
#include <vector>

#pragma once

template <typename T>
using Set = std::list<T>;
template <typename T>
using PowerSet = std::vector<Set<T>>;

template <typename T>
void generatePowerSet (const std::vector<T>& items, unsigned int i, unsigned int length, PowerSet<T>& result, Set<T> currentSet) {

  if (currentSet.size() > length) return;
  
  if (i == items.size() && currentSet.size() < length) return;
  
  if (i == items.size()) {
    result.emplace_back(currentSet);
    return;
  }

  generatePowerSet(items, i+1, length, result, currentSet);
  Set<T> withCurrentItem = currentSet;
  withCurrentItem.emplace_back(items[i]);
  generatePowerSet(items, i+1, length, result, withCurrentItem);
}

template <typename T>
PowerSet<T> powerSetParams (const std::vector<T>& items, unsigned int length) {
  PowerSet<T> result;
  generatePowerSet(items, 0, length, result, Set<T>());
  return result;
}




