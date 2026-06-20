#include <iostream>
#include <vector>
#include <unordered_map>

/* Given an integer array nums and an integer k, return the k most frequent elements within the array. 
 * The test cases are generated such that the answer is always unique. *You may return the output in any order. 
 * Input: nums = [1,1,2,2,2,3,3,3,3], k = 2 
 * Output: [2,3] 
 * First we create a freq vector, where we its an vector of vectors [[],[],[]...]
 * We create a result array, and then a hashmap to count how many times a number appears in the array.
 * After we iterate through the nums array to get the count, we iterate through the key, and values of the
 * hashmap, and append the count of numbers to the index of the freq array, which will have the value at the 
 * count index. That just means which number appears the most will be one of the last elements.
 * Then we iterate the frequency array backwards, and use another loop to get the numbers in the subarrays, and append it 
 * to our res array. Then if the res size is equal to k, it will just return the array, which should have 2 values.
 * */

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
    std::cout << '\n';
    return 0;
}
