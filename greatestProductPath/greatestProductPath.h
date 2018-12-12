//Given an nxn matrix, find the path from (0,0) to (n‐1, n‐1)
//by moving either right or down that has the greatest product.

#include <vector>
#include <list>

using std::list;
using std::vector;

struct Coordinate {
  unsigned int x, y;
  list<Coordinate> path;
};

int greatestProduct(const vector<vector<int>>& matrix);
list<Coordinate> greatestProductPath(const vector<vector<int>>& matrix);
