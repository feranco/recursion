#include <iostream>
#include <stdexcept>

unsigned int countingCombinations (unsigned int n) {

  //base case: only 1 combination with 0 objects (the empty combination)
  if (n == 0) return 1;

  unsigned int combinationWithN = countingCombinations(n-1);
  unsigned int combinationWithoutN = countingCombinations(n-1);

  return combinationWithN + combinationWithoutN;
}

int main (int argc, char** argv) {

  if (argc != 2) throw std::runtime_error("need the number of object as input");

  unsigned int n = atoi(argv[1]);
  std::cout << "The number of combinations of " << n << " objects is: " << countingCombinations(n) << "\n";
}
