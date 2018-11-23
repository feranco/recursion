#include "editDistance.h"
#include <iostream>

int main () {
  //string s1{"horse"}, s2{"ros"};
  string s1{"intention"}, s2{"execution"};
  auto res = editDistance(s1, s2);
  for (const string& s : res) std::cout << s << " ";
}
