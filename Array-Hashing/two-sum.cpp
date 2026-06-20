#include <iostream> #include <vector>
#include <unordered_map>

/* Two sum, basically you are looking for two numbers that equal to the target value.
 * You create a unordered_map, and then you make sure the key value pairs are ints.
 * The key is the value of the array, and the value of the map is the index of the array.
 * For example nums = {1,3,5}
 * The map would be {1:0,3:1,5:2}
 * Then you create a variable to subtract the target by the value of nums
 * If nums is inside of the map, you return it, because that means the specific index
 * where they found the answer in the map would both equal to the target.
 */


std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
  std::vector<std::vector<int>> freq(nums.size() + 1);
  std::vector<int> res;
  std::unordered_map<int, int> count;
  for (int num : nums) {
    count[num]++;
  }
  for (auto [key, value] : count) {
    freq[value].push_back(key);
  }
  for (int i = freq.size() - 1; i > 0; i--) {
    for (int n : freq[i]) {
      res.push_back(n);
      if (res.size() == k) {
        return res;
      }
    }
  }
  return res;
}

int main() {
  std::vector<int> nums = {1,1,2,2,2,3,3,3,3};
  int k = 2;
  std::vector<int> result = topKFrequent(nums, k);
  for (int num : result) {
    std::cout << num << " ";
  }
}
