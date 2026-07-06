#include <vector>
#include <iostream>
using namespace std;
/*
 * So you are using a binary search in a 2d matrix.
 * First thing you are doing is trying to figure out how many rows you have,
 * and how many columns exist in the 2d matrix. 
 * So to get the right side we R*C-1. Since we are basically converting 2d matrix into 
 * a 1d matrix in terms on indices. Then we compute the row and col. If we use integer
 * division with row, we would get the row, and modulo with col.
 * Then we do the ordinary binary search.
 *
 * */

bool searchMatrix(vector<vector<int>> matrix, int target) {
  int R = matrix.size();
  int C = matrix[0].size();
  int l = 0;
  int r = (R*C)-1;

  while (l<=r) {
    int mid = (l+r) / 2;
    int row = mid / C;
    int col = mid % C;
    if (matrix[row][col] == target) {
      return true;
    }
    else if (matrix[row][col] < target) {
      l = mid + 1;
    }
    else if (matrix[row][col] > target) {
      r = mid - 1;
    }
  }
  return false;
}

int main() {
  vector<vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };

  int target = 8;

  if (searchMatrix(matrix, target)) {
    cout << "Found\n";
  } else {
    cout << "Not found\n";
  }

  return 0;
}
