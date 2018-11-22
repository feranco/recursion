#include "longestIncreasingSubsequence.h"
#include <algorithm>

//Time complexity: O(2^n*n) The branching factor is 2, the depth is n (size of input sequence), each sequence is copied in linear time.
//Space complexity: O(n) space necessary to store the current sequece through the stack frame.
void longestIncreasingSubsequence (const list<int>& sequence, list<int>::const_iterator it, list<int>& currSequence, list<int>& result){

  if (it == sequence.end()) {
    if (currSequence.size() > result.size()) result = currSequence;
    return;
  }

  longestIncreasingSubsequence(sequence, next(it), currSequence, result);
  if (currSequence.empty() || currSequence.back() < *it) {
    currSequence.push_back(*it);
    longestIncreasingSubsequence(sequence, next(it), currSequence, result);
    currSequence.pop_back();
  }
}

list<int> longestIncreasingSubsequence (const list<int>& sequence) {
  list<int> result, currSequence;
  longestIncreasingSubsequence(sequence, sequence.cbegin(), currSequence, result);
  return result;
}
