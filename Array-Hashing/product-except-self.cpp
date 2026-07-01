#include <vector>
#include <iostream>


/*
 *Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].
 Each product is guaranteed to fit in a 32-bit integer.
 Follow-up: Could you solve it in O(n)O(n) time without using the division operation?
 Example 1:
 Input: nums = [1,2,4,6]
 Output: [48,24,12,8]
 * */

std::vector<int> productExceptSelf(std::vector<int>& nums) {

  std::vector<int> res (nums.size(),1);
  int postFix = 1;
  int prefix = 1;

  for (int i = 0; i < nums.size(); i++) {
    res[i] = prefix;
    prefix *= nums[i];
  }

  for (int i = nums.size()-1; i >= 0; i--) {
    res[i] *= postFix;
    postFix *= nums[i];
  }

  return res;
}


int main() {

  std::vector<int> nums = {1,2,4,6};
  std::vector<int> result = productExceptSelf(nums);

  for (int num : result) {
    std::cout << num << "\n";
  }



}
