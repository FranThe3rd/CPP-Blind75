#include <iostream>
#include <vector>
#include <algorithm>


/*
 * This is too much here https://youtu.be/TBePcj8DgxM
 */

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  int n = nums.size();
  vector<vector<int>> answer;
  for (int i = 0; i < n; i++) {
    if (nums[i] > 0)
      break;
    if (i > 0 && nums[i] == nums[i - 1])
      continue;
    int lo = i + 1;
    int hi = n - 1;

    while (lo < hi) {
      int sum = nums[i] + nums[lo] + nums[hi];
      if (sum == 0) {
        answer.push_back({nums[i], nums[lo], nums[hi]});
        lo++;
        hi--;
        while (lo < hi && nums[lo] == nums[lo - 1])
          lo++;

        while (lo < hi && nums[hi] == nums[hi + 1])
          hi--;
      }
      else if (sum < 0) {
        lo++;
      }
      else {
        hi--;
      }
    }
  }

  return answer;
}

int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> result = threeSum(nums);
  for (const auto& triplet : result) {
    cout << "[";
    for (int i = 0; i < triplet.size(); i++) {
      cout << triplet[i];
      if (i < triplet.size() - 1)
        cout << ", ";
    }
    cout << "]" << endl;
  }
  return 0;
}
