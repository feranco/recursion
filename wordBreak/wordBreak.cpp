#include "wordBreak.h"
#include <iostream>

//O(|s|^|s|) = O(|s|!) time. In the worst case the branching factor is |s| and the depth is also |s|.
//O(|s|^|s|*|s|) space necessary to store all the possible substring combinations.
void wordBreak2 (string s, unordered_set<string> dict, size_t k, string currentBreak, vector<string>& result) {

  if (k == s.size()) {
    result.push_back(currentBreak);
    return;
  }

  string restore = currentBreak;

  for (size_t len = 1; len <= (s.size()-k); ++len) {
    string word = s.substr(k,len);
    if (dict.find(word) != dict.end()) {
      std::cout << word << " " << k+len << "\n";
      currentBreak += (word + " ");
      wordBreak2(s, dict, k+len, currentBreak, result);
      currentBreak = restore;
    }
  }

}

//O(|dict|^|s|*|s|) = O(|s|!) time. In the worst case the branching factor is |dict| and the depth is |s|.
//O(|s|^|s|*|s|) space necessary to store all the possible substring combinations.
void wordBreak (string s, unordered_set<string> dict, size_t k, string currentBreak, vector<string>& result) {

  if (k == s.size()) {
    result.push_back(currentBreak);
    return;
  }

  string restore = currentBreak;
  for (string word : dict) {
    if (s.substr(k, word.size()) == word) {
      currentBreak += (word + " ");
      wordBreak(s, dict, k+word.size(), currentBreak, result);
      currentBreak = restore;
    }
  }
}


vector<string> wordBreakReturn (string s, unordered_set<string> dict, size_t k) {
  
  vector<string> result;
  
  if (k == s.size()) {
    result.emplace_back("");
    return result;
  }

  for (string word : dict) {
    if (s.substr(k, word.size()) == word) {
      auto res = wordBreakReturn(s, dict, k+word.size());
      for (string& s : res) {
	s = word + " " + s;
      }
      result.insert(result.begin(), res.begin(), res.end());
    }
  }
  return result;
}

vector<string> wordBreak (string s, unordered_set<string> dict) {
  /*vector<string> result;
  string currentBreak;
  wordBreak(s, dict, 0, currentBreak, result);
  */
  return wordBreakReturn(s, dict, 0);
}
