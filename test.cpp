// Copyright (c) 2025 Sungp2708. All Rights Reserved.

#include <bits/stdc++.h>
using namespace std;

void printV(vector<vector<int>> &v) {
  for (auto i : v) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {

  // An empty 2D vector
  vector<vector<int>> v1;

  // 2D vector with initial size and value
  vector<vector<int>> v2(2, vector<int>(3, 11));

  // A 2D vector initialized with initializer list
  vector<vector<int>> v3 = {
      {1, 2, 3},
      {4, 5, 6},
  };
  cout << v3.size() << endl;
  printV(v1);
  printV(v2);
  printV(v3);
  return 0;
}
