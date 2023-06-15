#include <bits/stdc++.h>
using namespace std;
bool checkIndexExist(int i, int j, bool isLeft) {
  // if is left is set then check for left else check for right
  if(isLeft) {
    // check if i-1 && j -1 exists
    if(i-1 < 0 || j - 1 < 0) return false;
    return true;
  }
  if(i-1 < 0 || j >= i) return false;
  return true;
}
vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  // top left -> i-1,j-1
  // top right -> i-1, j
  vector<vector< long long int>> pascalTringle;
  vector<long long int> temp(1,1);
  pascalTringle.push_back(temp);
  for(int i = 1; i < n; i++) {
    vector<long long int> currentTriangleRow;
    // check if index exist if yes then add it to the res
    // if res is zero add one
    for(int j = 0; j <= i; j++) {
      long long int res = 0;
      if(checkIndexExist(i,j, true)) res+=pascalTringle[i-1][j-1];
      if(checkIndexExist(i,j, false)) res+=pascalTringle[i-1][j];
      currentTriangleRow.push_back(res);
    }
    pascalTringle.push_back(currentTriangleRow);
  }
  return pascalTringle;
}

int main() {
    return 0;
}