#include "numberOfAtoms.h"
#include <map>

//O(n*logN) time: in the worst case the number of atoms is equal to number of nested formulas
//(i.e. A(B(C(D(E(F(G)2)2)2)2)2)2). So, in every step the number of atoms to merge is O(n)
//and every update require log(N) time.
//O(n) space necessary to keep track of the multiplicity of each atom

using atomsMap = std::map<string,int>;
    
string getAtom(const string& formula, size_t& idx) {
  size_t start = idx++;
  while (idx < formula.size() && islower(formula[idx])) idx++;
  int len = idx - start;
  return formula.substr(start, len);
}
    
void merge(atomsMap& a, atomsMap& b) {
  for (const auto& item : b) a[item.first] += item.second;      
} 
    
int getMultiplicity(const string& formula, size_t& idx) {
  size_t start = idx;
  while (idx < formula.size() && isdigit(formula[idx])) idx++;
  int len = idx - start;
  if (len > 0) return stoi(formula.substr(start, len));
  else return 1;
}
    
void applyMultiplicity(int mult, atomsMap& atomsCounter) {
  for (auto& atoms : atomsCounter) atoms.second *= mult;        
}
    
atomsMap countOfAtoms(string formula, size_t& idx) {
        
  atomsMap result;
        
  while (idx < formula.size()) {

    //return from nested formula
    if (formula[idx] == ')') {
      idx++;
      break;
    }

    //nested formula
    if (formula[idx] == '(') {
      auto nestedResult = countOfAtoms(formula, ++idx);
      size_t mult = getMultiplicity(formula, idx);
      applyMultiplicity(mult, nestedResult);
      merge(result, nestedResult);
    }
    else {//parse current formula
      string atom = getAtom(formula, idx);
      size_t mult = getMultiplicity(formula, idx);
      result[atom] += mult;
    }        
  }
  return result;
}
    
string countOfAtoms(string formula) {
  size_t idx = 0;
  string result;
  for (const auto& atoms : countOfAtoms(formula, idx)) {
    result.append(atoms.first);
    if (atoms.second > 1) 
      result.append(std::to_string(atoms.second));
  }
  return result;
}
