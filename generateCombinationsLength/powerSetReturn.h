#include <list>
#include <vector>

#pragma once

template <typename T>
using Set = std::list<T>;
template <typename T>
using PowerSet = std::vector<Set<T>>;

template <typename T>
PowerSet<T> generatePowerSet (const std::vector<T>& items, unsigned int idx, unsigned int targetLength, unsigned int currentLength) {

  PowerSet<T> result;

  //return the empty power set: no power set can be generated if
  //the current length exceeds the target one or if it's less than the
  //target one when all the elements has been already included/excluded
  if (currentLength > targetLength) return result;
  if (idx == items.size() && currentLength < targetLength) return result;

  if (idx == items.size()) {
    result.emplace_back(Set<T>());
    return result;
  }

  auto withoutCurrentItem = generatePowerSet(items, idx+1, targetLength, currentLength);
  auto withCurrentItem = generatePowerSet(items, idx+1, targetLength, currentLength+1);

  result = withoutCurrentItem;

  for (auto& set : withCurrentItem) {
    set.emplace_front(items[idx]);
    result.emplace_back(set);
  }

  return result;
}

template <typename T>
PowerSet<T> powerSetReturn (const std::vector<T>& items, unsigned int length) {
  return generatePowerSet(items, 0, length, 0);
}
