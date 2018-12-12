#include "knightProbability.h"
#include <iostream>

int main (int argc, char** argv) {
  if (argc == 5) {
    int N = atoi(argv[1]);
    int K = atoi(argv[2]);
    
    int r = atoi(argv[3]);
    int c = atoi(argv[4]);
    std::cout << knightProbability(N, K, r, c);
  }
  else {
    std::cout << knightProbability(3, 2, 0, 0);
  }
}
