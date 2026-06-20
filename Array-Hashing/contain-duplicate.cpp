#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>
#include <unordered_set>


/* Contain Duplicates, you are looking if an array contain duplicates.
 * You create a unoredered_set, instead of a normal set since its much faster.
 * Loop the array, and then check if your set has it, if it does, that means it contains a duplicate.
 * Then insert values to set to keep going.
 */

bool containDuplicate(std::vector<int> nums) {

  std::unordered_set<int> mySet;
  for (int num : nums) {
    if (mySet.count(num)) {
      return true;
    }
    mySet.insert(num);
  }
  return false;

}


int main() {
  std::vector<int> nums = {2,4,6,1,2};
  bool result = containDuplicate(nums);
  std:: cout << result;
  std::vector<int> nums2 = {2,4,6,1,};
  bool result2 = containDuplicate(nums2);
  std:: cout << result2;
}






