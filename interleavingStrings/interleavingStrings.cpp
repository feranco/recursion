#include "interleavingStrings.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>

vector<string> interleave (const string& s1, const string& s2, size_t i, size_t j) {
  
  if (i == s1.size() && j == s2.size()) {
    return vector<string>{""};
  }
  
  vector<string> resultS1;
  if (i < s1.size()) {
    resultS1 = interleave(s1, s2, i+1, j);
    for (auto& s : resultS1) {
      s.push_back(s1[i]);
    }
  }

  vector<string> resultS2;
  if (j < s2.size()) {
    resultS2 = interleave(s1, s2, i, j+1);
    for (auto& s : resultS2) {
      s.push_back(s2[j]);
    }
  }

  vector<string> result = resultS1;
  result.insert(result.end(), resultS2.begin(), resultS2.end());
  return result;
}

void interleave (const string& s1, const string& s2, size_t i, size_t j, string interleaved, vector<string>& result) {
  
  if (i == s1.size() && j == s2.size()) {
    result.emplace_back(interleaved);
    return;
  }

  if (i < s1.size()) {
    interleaved.push_back(s1[i]);
    interleave(s1, s2, i+1, j, interleaved, result);
    interleaved.pop_back();
  }

  if (j < s2.size()) {
    interleaved.push_back(s2[j]);
    interleave(s1, s2, i, j+1, interleaved, result);
    interleaved.pop_back();
  }
  
}

vector<string> interleave (const string& s1, const string& s2) {
  vector<string> resultParams;
  interleave(s1, s2, 0, 0, string(), resultParams);

  //the return version build the string in reverse order
  auto resultReturn = interleave(s1, s2, 0, 0);
  for (auto& s : resultReturn) reverse(s.begin(), s.end());
  
  if (!std::equal(resultParams.begin(), resultParams.end(), resultReturn.begin())) {
    throw std::runtime_error("powerSetParams different from powerSetReturn");
  }

  return resultParams;}
