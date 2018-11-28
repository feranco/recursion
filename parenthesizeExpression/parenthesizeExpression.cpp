#include "parenthesizeExpression.h"

vector<string> parenthesizeExpression (const string& expr) {

  if (expr.size() == 1) return vector<string>{expr};

  vector<string> result;

  for (size_t len = 1; len < expr.size(); ++len) {
    auto left = parenthesizeExpression(expr.substr(0, len));
    auto right = parenthesizeExpression(expr.substr(len)); //substr without 2nd argument mean up to the end of the string
    for (auto& s1 : left) {
      for (auto& s2 : right) {
	result.emplace_back("("+s1+s2+")");
      }
    }
  }
  return result;
}
