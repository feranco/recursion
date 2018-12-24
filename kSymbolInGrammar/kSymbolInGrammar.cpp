#include "kSymbolInGrammar.h"
#include <cmath>

//The length of the current word is 2^(n-1)
//if k is less than the half of the length of the current word, the result is the value of k in the previous word.
//If k is more then the half of the length of the current word, k can be reduced to a smaller index in the previous word
//and the result is obtained flipping the value of this new index.
//O(n) time, O(n) space
int kthGrammar(int N, int K) {
        
  if (N == 1) return 0;
        
  int nextLength = std::pow(2,N-1) / 2;
  int nextK = (K <= nextLength) ? K : K - nextLength; 
        
  int prevValueK = kthGrammar(N-1, nextK);
        
  return (nextK == K) ? prevValueK : (1-prevValueK);
}
