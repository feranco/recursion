#include "knapsack01Dfs.h"

void knapsack(const vector<Item>& items, unsigned int capacity, State s, unordered_set<State, StateHash, StateEq>& visited, State& result) {

  if (visited.find(s) != visited.end() || s.getWeight(items) > capacity) return;
  
  visited.insert(s);
  
  if (s.getValue(items) > result.getValue(items)) result = s;
  

  for (auto state : s.adjacentStates()) {
    knapsack(items, capacity, state, visited, result);
  }
  
}


Result knapsack01Dfs(const vector<Item>& items, unsigned int capacity) {
  Result r;
  unordered_set<State, StateHash, StateEq> visited;
  State s{items.size()}, result{items.size()};
  
  knapsack(items, capacity, s, visited, result);
  
  r.value = result.getValue(items);
  for (size_t i = 0; i < result.isInKnapsack.size(); ++i) {
    if(result.isInKnapsack[i]) r.items.push_back(i);
  }    
  return r;
}
