#include "knapsack01.h"

void knapsack01 (const vector<Item>& items, uint capacity, uint k, uint knapsackWeight, uint knapsackValue, vector<uint>& knapsackItems, Result& result) {

  if (knapsackWeight > capacity) return;

  if (k == items.size()) {
    if (knapsackValue > result.value) {
      result.value = knapsackValue;
      result.items = knapsackItems;
    }
    return;
  }

  knapsack01(items, capacity, k+1, knapsackWeight, knapsackValue, knapsackItems, result);
  knapsackItems.push_back(k);
  knapsack01(items, capacity, k+1, knapsackWeight+items[k].weight, knapsackValue+items[k].value, knapsackItems, result);
  knapsackItems.pop_back();
}

Result knapsack01Params (const vector<Item>& items, unsigned int capacity) {
  Result result{vector<uint>(), 0};
  vector<uint> knapsackItems;
  knapsack01(items, capacity, 0, 0, 0, knapsackItems, result);
  return result;
};
