#include "arrayOfArrays.h"
#include <algorithm>
#include <stdexcept>

vector<vector<int>> arrayOfArrays(const vector<vector<int>>& arr2d, unsigned int k) {
  
  vector<vector<int>> result;
  if (k == arr2d.size()) {
    result.emplace_back(vector<int>{});
    return result;
  }

  for (unsigned int i = 0; i < arr2d[k].size(); ++i) {
    auto res = arrayOfArrays(arr2d, k+1);
    for (auto& arr : res) {
      arr.push_back(arr2d[k][i]);
    }
    result.insert(result.begin(), res.begin(), res.end()); 
  }

  return result;
}

//Time Complexity: O(max(|arr1d|)^|arr2d|*|arr2d|) In the worst case the branching factor is the size of the bigger 1d array
// and the depth is the number of 1d arrays contained in the 2d array. Each combination is then copied in O(|arr2d|)
//O(max(|arr1d|)^|arr2d|*|arr2d|) is the space necessary to store all the possible substring combinations.
void arrayOfArrays(const vector<vector<int>>& arr2d, unsigned int k, vector<int>& arr1d, vector<vector<int>>& result) {

  if (k == arr2d.size()) {
    result.push_back(arr1d);
    return;
  }

  for (unsigned int i = 0; i < arr2d[k].size(); ++i) {
    arr1d.push_back(arr2d[k][i]);
    arrayOfArrays(arr2d, k+1, arr1d, result);
    arr1d.pop_back();
  }
}

vector<vector<int>> arrayOfArrays(const vector<vector<int>>& arr) {
  
  vector<vector<int>> resultParams;
  vector<int> arr1D;
  arrayOfArrays(arr, 0, arr1D, resultParams);

  //the return version build the string in reverse order
  auto resultReturn = arrayOfArrays(arr, 0);
  reverse(resultReturn.begin(), resultReturn.end());
  for (auto& arr : resultReturn) reverse(arr.begin(), arr.end());
  
  if (!std::equal(resultParams.begin(), resultParams.end(), resultReturn.begin())) {
    throw std::runtime_error("resultParams different from resultReturn");
  }
  
  return resultParams;
}
