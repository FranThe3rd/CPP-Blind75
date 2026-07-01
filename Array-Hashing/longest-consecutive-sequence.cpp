#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>


/*
 * Given an array of integers nums, return the length of the longest consecutive sequence of elements that can be formed.
 * A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous element. The elements do not have to be consecutive in the original array.
 * You must write an algorithm that runs in O(n) time.
 * Example 1:
 * Input: nums = [2,20,4,10,3,4,5]
 * You start of creating a hashset that is equal to nums, since looking up values in a set is O(1).
 * Then we check if the number - 1 doesnt exist in set, if it doesn't exist that means its the first value on the sequence.
 * Then you set length to one since thats the first numbner, and use a while loop to add num plus the length, if num
 * plus the length still exist in the set, then you jsut increase the length and longest keep track about the longest sequence.
*/
int longestConsecutive(std::vector<int> nums) {

  std::unordered_set<int> num_set(nums.begin(),nums.end());
  int longest = 0;
  for (int num: nums) {
    if (!num_set.count(num-1)) {
      int length = 1;
      while (num_set.count(num+length)) {
        length += 1;
        longest = std::max(length,longest);
      }
    }
  }

  return longest;
}


int main() {
  std::vector<int> nums = {2,20,4,10,3,4,5};
  int result = longestConsecutive(nums);
  std::cout << result;
}
