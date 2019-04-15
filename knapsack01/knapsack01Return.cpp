#include "knapsack01.h"

Result knapsack01 (const vector<Item>& items, uint capacity, uint k, uint knapsackWeight, uint knapsackValue) {

  Result result{vector<uint>(),0};

  if (knapsackWeight > capacity) return Result{{}, 0};

  if (k == items.size()) return Result{{}, knapsackValue};

  auto withoutCurrentItem = knapsack01(items, capacity, k+1, knapsackWeight, knapsackValue);
  auto withCurrentItem = knapsack01(items, capacity, k+1, knapsackWeight+items[k].weight, knapsackValue+items[k].value);
  withCurrentItem.items.push_back(k);


  return (withCurrentItem.value > withoutCurrentItem.value) ? withCurrentItem : withoutCurrentItem;


}

Result knapsack01Return (const vector<Item>& items, unsigned int capacity) {
  return knapsack01(items, capacity, 0, 0, 0);
};
