//On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts
//to make exactly K moves. Each time the knight is to move, it chooses one of eight
//possible moves uniformly at random (even if the piece would go off the chessboard)
//and moves there. The knight continues moving until it has made exactly K moves or
//has moved off the chessboard. Find the probability that the knight remains on the
//board after it has stopped moving.

//Time complexity O(8^(8^k))

#include "knightProbability.h"
#include <initializer_list>
#include <cmath>

double validEndingPositions(int N, int K, int r, int c) {
        
  if (r < 0 || c < 0 || r > N-1 || c > N-1) return 0;
        
  if (K == 0) return 1;
        
  int res = 0.0;
  for (int x : {-2, 2}) {
    for (int y : {-1, 1}) {
      res += validEndingPositions(N, K-1, r+x, c+y);
      res += validEndingPositions(N, K-1, r+y, c+x);
    }
  }
        
  return res;
}

//probability = number of effective ending position on the board
//divided by the number of the possible ending positions
//since there are 8 possible choices for each moves, the
//number of possible ending positions is 8^k
double knightProbability(int N, int K, int r, int c) {
  const double totalEndingPositions = std::pow(8,K);
  double pos = validEndingPositions(N, K, r, c);
  return pos / totalEndingPositions;
}
