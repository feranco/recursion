#pragma once
#include "knapsack01.h"
#include <unordered_set>

using std::unordered_set;

class State {
 public:
  State (size_t size) {
    isInKnapsack.resize(size,0);
  }
  
  /*
  Copy constructor and assignment operator don't need to be defined since std::vector already implement them  
  State (const State& state) {
    isInKnapsack.assign(state.isInKnapsack.begin(), state.isInKnapsack.end());
  }

  State& operator=(const State& state) {

    if(&state == this)
      return *this;
    isInKnapsack.assign(state.isInKnapsack.begin(), state.isInKnapsack.end());
    //std::cout << "c=" << value << " " << isInKnapsack.size() <<"\n";
    return *this;
  }
  */
  
  uint getValue (const vector<Item>& items) const{
    uint res = 0;
    for (unsigned int i = 0; i < isInKnapsack.size(); ++i) {
      if (isInKnapsack[i]) res += items[i].value;
    }
    return res;
  }

   uint getWeight (const vector<Item>& items) const{
    uint res = 0;
    for (unsigned int i = 0; i < isInKnapsack.size(); ++i) {
      if (isInKnapsack[i]) res += items[i].weight;
    }
    return res;
  }

  vector<State> adjacentStates () {

    vector<State> adjacents;
    
    for (unsigned int i = 0; i < isInKnapsack.size(); ++i) {
      isInKnapsack[i] = (isInKnapsack[i] == false) ? true : false;
      adjacents.push_back(*this);
      isInKnapsack[i] = (isInKnapsack[i] == false) ? true : false;
    }

    return adjacents;
  }

  //private:
  vector<bool> isInKnapsack;
};

class StateEq {
 public:
  bool operator()(const State& lhs, const State& rhs) const {
    if (lhs.isInKnapsack.size() != rhs.isInKnapsack.size()) return false;
    for (unsigned int i = 0; i < lhs.isInKnapsack.size(); ++i) {
      if (lhs.isInKnapsack[i] != rhs.isInKnapsack[i]) return false;
    }
    return true;
  }
};

class StateHash {
 public:
  std::size_t operator()(const State& state) const{
    std::hash<vector<bool>> hvb;
    return hvb(state.isInKnapsack);
  }
};

Result knapsack01Dfs(const vector<Item>& items, unsigned int capacity);
