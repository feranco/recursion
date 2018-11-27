#include "parenthesizeExpression.h"
#include <iostream>
int main() {
  auto res = parenthesizeExpression("abcd");
  for (const auto& s : res) std::cout << s << " ";
}
