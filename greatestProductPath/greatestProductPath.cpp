//Given an nxn matrix, find the path from (0,0) to (n‐1, n‐1)
//by moving either right or down that has the greatest product.
//O(2^(nxn)) time and space complexity (for each cell of the matrix there are two options
//and all the possible paths are investigated
#include "greatestProductPath.h"
#include <algorithm>
#include <iostream>
using std::max;
using std::min;

//Find the maximum product by building up the results while returning.
//In order to work for negative values, the function needs to keep track
//of both the maximum and minimum values that can be obtained multiplying the
//current value with the min/max value of the path coming from down and the
//min/max value of the path coming from right
vector<int> greatestProduct(const vector<vector<int>>& matrix, Coordinate pos) {
  
  if (pos.x == matrix.size()-1 && pos.y == matrix[0].size()-1) {
    return vector<int>{matrix[pos.x][pos.y], matrix[pos.x][pos.y]};
  }

  if (pos.x >= matrix.size() || pos.y >= matrix[0].size()) return vector<int>{};

  auto down  = greatestProduct(matrix,{pos.x+1, pos.y});
  auto right = greatestProduct(matrix,{pos.x, pos.y+1});

  vector<int> result;
  
  if (down.size() > 0) {
    result.emplace_back(min(down[0]*matrix[pos.x][pos.y], down[1]*matrix[pos.x][pos.y]));
    result.emplace_back(max(down[0]*matrix[pos.x][pos.y], down[1]*matrix[pos.x][pos.y]));
  }

  if (right.size() > 0) {
    if (result.size() > 0) {
      result[0] = min(result[0], min(right[0]*matrix[pos.x][pos.y], right[1]*matrix[pos.x][pos.y]));
      result[1] = max(result[1], max(right[0]*matrix[pos.x][pos.y], right[1]*matrix[pos.x][pos.y]));
    }
    else {
      result.emplace_back(min(right[0]*matrix[pos.x][pos.y], right[1]*matrix[pos.x][pos.y]));
      result.emplace_back(max(right[0]*matrix[pos.x][pos.y], right[1]*matrix[pos.x][pos.y]));
    }
  }

  return result;
}

int greatestProduct(const vector<vector<int>>& matrix) {
  auto res = greatestProduct(matrix, {0,0});
  return *max_element(res.begin(), res.end());
}

struct Result {
  vector<int> minmax;
  vector<list<Coordinate>> path;
};

//Find the actual path by building up it while returning.
Result greatestProductPath(const vector<vector<int>>& matrix, Coordinate pos) {

  Result result;

  if (pos.x == matrix.size()-1 && pos.y == matrix[0].size()-1) {
    
    result.minmax.emplace_back(matrix[pos.x][pos.y]);
    result.minmax.emplace_back(matrix[pos.x][pos.y]);
    result.path.emplace_back(list<Coordinate>{Coordinate{pos.x,pos.y}});
    result.path.emplace_back(list<Coordinate>{Coordinate{pos.x,pos.y}});
    return result;
  }

  if (pos.x >= matrix.size() || pos.y >= matrix[0].size()) return Result{};

  auto down  = greatestProductPath(matrix,{pos.x+1, pos.y});
  auto right = greatestProductPath(matrix,{pos.x, pos.y+1});
  
  if (down.minmax.size() > 0) {
    int minIdx = 0, maxIdx = 1;
    if (down.minmax[0]*matrix[pos.x][pos.y] < down.minmax[1]*matrix[pos.x][pos.y]) {
      minIdx = 0;
      maxIdx = 1;
    }
    else {
      minIdx = 1;
      maxIdx = 0;
    }
    
    result.minmax.emplace_back(down.minmax[minIdx]*matrix[pos.x][pos.y]);
    result.minmax.emplace_back(down.minmax[maxIdx]*matrix[pos.x][pos.y]);
    
    result.path.push_back(down.path[minIdx]);
    result.path.push_back(down.path[maxIdx]);
    
    result.path[0].emplace_front(Coordinate{pos.x,pos.y});
    result.path[1].emplace_front(Coordinate{pos.x,pos.y});
  }
  
  if (right.minmax.size() > 0) {
    
    int minIdx, maxIdx;
    if (right.minmax[0]*matrix[pos.x][pos.y] < right.minmax[1]*matrix[pos.x][pos.y]) {
      minIdx = 0;
      maxIdx = 1;
    }
    else {
      minIdx = 1;
      maxIdx = 0;
    }
    
    if (result.minmax.size() > 0) {
      if (result.minmax[0] > right.minmax[minIdx]*matrix[pos.x][pos.y]) {
	 result.minmax[0] = right.minmax[minIdx]*matrix[pos.x][pos.y];
	 result.path[0] = right.path[minIdx];
	 result.path[0].emplace_front(Coordinate{pos.x,pos.y});
      }
      
      if (result.minmax[1] < right.minmax[maxIdx]*matrix[pos.x][pos.y]) {
	 result.minmax[1] = right.minmax[maxIdx]*matrix[pos.x][pos.y];
	 result.path[1] = right.path[maxIdx];
	 result.path[1].emplace_front(Coordinate{pos.x,pos.y});
      }
    }
    else {
      result.minmax.emplace_back(right.minmax[minIdx]*matrix[pos.x][pos.y]);
      result.minmax.emplace_back(right.minmax[maxIdx]*matrix[pos.x][pos.y]);
      result.path.push_back(right.path[minIdx]);
      result.path.push_back(right.path[maxIdx]);
      result.path[0].emplace_front(Coordinate{pos.x,pos.y});
      result.path[1].emplace_front(Coordinate{pos.x,pos.y});
    }
  }
  
  return result;
}

list<Coordinate> greatestProductPath(const vector<vector<int>>& matrix) {
  auto result =  greatestProductPath(matrix, {0,0});
  if (result.minmax[0] > result.minmax[1]) return result.path[0];
  else return result.path[1];   
}


