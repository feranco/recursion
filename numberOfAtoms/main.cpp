#include "numberOfAtoms.h"
#include <iostream>

int main (int argc, char** argv) {
  string formula{"K4(ON(SO3)2)2"};
  if (argc > 1) formula = argv[1];
  std::cout << countOfAtoms(formula);  
}


