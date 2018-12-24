#include "kSymbolInGrammar.h"
#include <iostream>
#include <cstdlib>
#include <stdexcept>

int main(int argc, char** argv) {
  if (argc != 3) std::runtime_error("insert two args: n and k\n");
  std::cout << kthGrammar(atoi(argv[1]), atoi(argv[2]));
}
