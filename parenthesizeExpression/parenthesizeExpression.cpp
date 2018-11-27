#include "parenthesizeExpression.h"

vector<string> parenthesizeExpression (const string& expr) {

  if (expr.size() == 2) return vector<string>{"("+expr+")"};
  if (expr.size() == 1) return vector<string>{expr};

  vector<string> result;

  for (size_t len = 0; len < expr.size()-1; ++len) {
    auto l = parenthesizeExpression(expr.substr(0, len+1));
    auto r = parenthesizeExpression(expr.substr(len+1));
    for (auto& s1 : l) {
      for (auto& s2 : r) {
	result.emplace_back("("+s1+s2+")");
      }
    }
  }
  return result;
}
