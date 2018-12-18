#include "partitionEqualSumSubset.h"
#include <algorithm>

//O(k!) time nd O(n) space
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
    //this line avoid to place a number in an empty subset multiple time
    //saving repeated work
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
