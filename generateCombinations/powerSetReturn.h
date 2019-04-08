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
    result.emplace_back(Set<T>{});
    return result;
  }

  for (auto& set : generatePowerSet(items, i+1)) {
    result.emplace_back(set);
    set.emplace_front(items[i]);
    result.emplace_back(set);
  }

  return result;
}

template <typename T>
PowerSet<T> powerSetReturn (const std::vector<T>& items) {
  return generatePowerSet(items, 0);
}
