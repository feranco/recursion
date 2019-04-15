#include <list>
#include <vector>

#pragma once

template <typename T>
using Set = std::list<T>;
template <typename T>
using PowerSet = std::vector<Set<T>>;

template <typename T>
void generatePowerSet (const std::vector<T>& items, unsigned int idx, unsigned int targetLength, PowerSet<T>& result, Set<T> currentSet) {

  if (currentSet.size() == targetLength) {
    result.push_back(currentSet);
    return;
  }

  if (idx == items.size()) return;

  generatePowerSet(items, idx+1, targetLength, result, currentSet);
  Set<T> withCurrentItem = currentSet;
  withCurrentItem.emplace_back(items[idx]);
  generatePowerSet(items, idx+1, targetLength, result, withCurrentItem);
}

template <typename T>
PowerSet<T> powerSetParams (const std::vector<T>& items, unsigned int targetLength) {
  PowerSet<T> result;
  generatePowerSet(items, 0, targetLength, result, Set<T>());
  return result;
}
