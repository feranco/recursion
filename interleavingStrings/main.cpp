#include "interleavingStrings.h"
#include <iostream>
#include <stdexcept>

int main (int argc, char** argv) {

  if (argc != 3) throw std::runtime_error("pass two string as arguments");
  string s1{argv[1]}, s2{argv[2]};
  auto result = interleave(s1,s2);
  for (auto s : result) std::cout << s << " "; 
}
