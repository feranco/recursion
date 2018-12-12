#include "greatestProductPath.h"
#include <iostream>

int main (void) {  
  vector<vector<int>> matrix{{-1,2,3},{4,5,6},{-7,8,9}};
  std::cout << "Product = " << greatestProduct(matrix) << "\n";
  auto res = greatestProductPath(matrix);
  for(const auto& c : res) {
    std::cout << "(" << c.x << " " << c.y << ") = "<< matrix[c.x][c.y] << ", ";
  }
}



