#include <list>
#include <vector>

#pragma once

template <typename T>
using Set = std::list<T>;
template <typename T>
using PowerSet = std::vector<Set<T>>;

template <typename T>
PowerSet<T> generatePowerSet (const std::vector<T>& items, unsigned int i, unsigned int length, unsigned int currentLength) {

  PowerSet<T> result;

  if (currentLength > length) return result;

  if (i == items.size() && currentLength < length) return result;
  
  if (i == items.size()) {
    result.emplace_back(Set<T>());
    return result;
  }

  auto withoutCurrentItem = generatePowerSet(items, i+1, length, currentLength);
  auto withCurrentItem = generatePowerSet(items, i+1, length, currentLength+1);

  result = withoutCurrentItem;

  for (auto& set : withCurrentItem) {
    set.emplace_front(items[i]);
    result.emplace_back(set);
  }
  
  return result;
}

template <typename T>
PowerSet<T> powerSetReturn (const std::vector<T>& items, unsigned int length) {
  return generatePowerSet(items, 0, length, 0);
}




