#include <list>
#include <vector>

#pragma once

template <typename T>
using Set = std::list<T>;
template <typename T>
using PowerSet = std::vector<Set<T>>;

template <typename T>
PowerSet<T> generatePowerSet (const std::vector<T>& items, unsigned int i) {

  PowerSet<T> result;
  
  if (i == items.size()) {
    result.emplace_back(Set<T>());
    return result;
  }

  auto withoutCurrentItem = generatePowerSet(items, i+1);
  result = withoutCurrentItem;//duplicate to use in for cycle

  for (auto& set : withoutCurrentItem) {
    set.emplace_front(items[i]);
    result.emplace_back(set);
  }
  
  return result;
}

template <typename T>
PowerSet<T> powerSetReturn (const std::vector<T>& items) {
  return generatePowerSet(items, 0);
}




