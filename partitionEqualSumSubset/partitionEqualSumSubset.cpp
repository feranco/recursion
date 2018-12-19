#include "partitionEqualSumSubset.h"
#include <algorithm>

//O(k!*k^(n-k)) time and O(n) space, where n is nums.size()
//the time complexity might have been O(k^n) without the line if (subsetSum[j] == 0) break;
//with this line the for loop (and the recursive call) is executed once for nums[0],
//twice for nums[1], k times for nums[k-1] and this is equal to k!
//for nums[k], ..., nums[n-1] the for loop is executed always k times and this is equal to k^(n-k)
//because k is the branching factor and n-k is the deep
bool canPartitionKSubsets(const vector<int>& nums, size_t idx, int maxSum, vector<int>& subsetSum) {
        
  if (idx == nums.size()) return true;
        
  for (size_t j = 0; j < subsetSum.size(); ++j) {
    subsetSum[j] += nums[idx];
    if (subsetSum[j] <= maxSum) {
      if(canPartitionKSubsets(nums, idx+1, maxSum, subsetSum)) {
	return true;
      }
    }
    subsetSum[j] -= nums[idx];
    //this line avoid to place a number in an empty subset multiple time saving repeated work
    if (subsetSum[j] == 0) break;
  }
        
  return false;
}
    
bool canPartitionKSubsets(const vector<int>& nums, int k) {
        
  int numsSum = accumulate(nums.begin(), nums.end(), 0);

  if (numsSum % k != 0) return false;
        
  int maxSum = numsSum / k;
  vector<int> subsetSum(k, 0);
        
  return canPartitionKSubsets(nums, 0, maxSum, subsetSum);
}
