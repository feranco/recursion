#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

//Time Complexity: O(n^n*n) = O(n!*n). The branching factor and the depth are both n. Each permutation is copied in linear time.
//Space Complexity: O(n^n*n). Space needed to store all permutations.
template <typename T>
void generatePermutations (unordered_set<T>& items, vector<T>& currentPermutation, vector<vector<T>>& permutations) {

  if (items.empty()) {
    permutations.push_back(currentPermutation);
    return;
  }

  auto dup = items;

  for (const auto& item : dup) {
    currentPermutation.push_back(item);
    items.erase(item);
    generatePermutations(items, currentPermutation, permutations);
    items.insert(item);
    currentPermutation.pop_back();
  }
  
}

template <typename T>
vector<vector<T>> generatePermutations (unordered_set<T>& items) {
  vector<vector<T>> permutations;
  vector<T> currentPermutation;
  generatePermutations(items, currentPermutation, permutations);
  return permutations;
}
