#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>
#include <unordered_set>



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






