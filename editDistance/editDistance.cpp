#include "editDistance.h"
#include <iostream>

void editDistance (string s1, const string& s2, size_t i, size_t j, vector<string>& currentEdit, vector<string>& result);

void insert (string s1, const string& s2, size_t i, size_t j, vector<string>& currentEdit, vector<string>& result) {
  s1.insert(i, 1, s2[j]);
  currentEdit.push_back(s1);
  editDistance(s1, s2, i, j, currentEdit, result);
  currentEdit.pop_back();
}

void cancel (string s1, const string& s2, size_t i, size_t j, vector<string>& currentEdit, vector<string>& result) {
  s1.erase(i,1);
  currentEdit.push_back(s1);
  editDistance(s1, s2, i, j, currentEdit, result);
  currentEdit.pop_back();
}


void change (string s1, const string& s2, size_t i, size_t j, vector<string>& currentEdit, vector<string>& result) {
  s1[i] = s2[j];
  currentEdit.push_back(s1);
  editDistance(s1, s2, i+1, j+1, currentEdit, result);
  currentEdit.pop_back();
}

void storeResult (vector<string>& currentEdit, vector<string>& result) {
  if (result.empty() || currentEdit.size() < result.size()) {
      result = currentEdit;
    }
}

void editDistance (string s1, const string& s2, size_t i, size_t j, vector<string>& currentEdit, vector<string>& result) {

  //base case 1: s1 and s2 are equal
  if (i == s1.size() && j == s2.size()) {
    storeResult(currentEdit, result);
    return;
  }

  //base case 2: s1 and s2 are equal, but s1 has additional chars to be removed
  if (j == s2.size()) {
    cancel(s1, s2, i, j, currentEdit, result);
    return;
  }

  //base case 3: s1 and s2 are equal, but s1 has additional missing chars to be added
  if (i == s1.size()) {
    insert(s1, s2, i, j, currentEdit, result);
    return;
  }
        
  //matching characters
  if (s1[i] == s2[j]) {
    editDistance(s1, s2, i+1, j+1, currentEdit, result);
  }
  else {
    insert(s1, s2, i, j, currentEdit, result);
    cancel(s1, s2, i, j, currentEdit, result);
    change(s1, s2, i, j, currentEdit, result);
  }
}

vector<string> editDistance (string& s1, const string& s2) {
  vector<string> currentEdit{s1}, result;
  editDistance(s1, s2, 0, 0, currentEdit, result);
  return result;
}
