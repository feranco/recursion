#include "wordBreak.h"
#include <iostream>

int main (int argc, char**argv) {

  if (argc == 1) {
    string s{"applepineapple"};
    unordered_set<string> dict{"apple", "pine", "pineapple"};
    auto result = wordBreak(s, dict);
    for (const string& s : result) std::cout << s << "\n";
  }
  else {
    string s{argv[1]};
    unordered_set<string> dict;
    for (int i = 2; i < argc; ++i) {
      dict.insert(string(argv[i]));
    }
    auto result = wordBreak(s, dict);
    for (const string& s : result) std::cout << s << "\n";
  }

  
}
