#pragma once

#include <vector>

using std::vector;
using uint = unsigned int;

struct Item {
  uint weight;
  uint value;
};

struct Result {
  vector<uint> items;
  uint value;
};
