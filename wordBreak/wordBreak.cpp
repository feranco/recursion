#include "wordBreak.h"
#include <iostream>

//O(|s|^|s|*|s|) time. In the worst case the branching factor is |s| and the depth is also |s|.
//Each decomposition is then copied in O(|s|)
//O(|s|^|s|*|s|) space necessary to store all the possible substring combinations.
void wordBreak2 (string s, unordered_set<string> dict, size_t k, string currentBreak, vector<string>& result) {

  if (k == s.size()) {
    result.emplace_back(currentBreak);
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

//O(|dict|^|s|*|s|) time. In the worst case the branching factor is |dict| and the depth is |s|.
//Each decomposition is then copied in O(|s|)
//O(|s|^|s|*|s|) space necessary to store all the possible substring combinations.
void wordBreak (string s, unordered_set<string> dict, size_t k, string currentBreak, vector<string>& result) {

  if (k == s.size()) {
    result.emplace_back(currentBreak);
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


vector<string> wordBreak (string s, unordered_set<string> dict) {
  vector<string> result;
  string currentBreak;
  wordBreak(s, dict, 0, currentBreak, result);
  return result;
}
