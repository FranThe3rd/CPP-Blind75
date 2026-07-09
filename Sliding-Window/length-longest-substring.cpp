#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <string>

/*
 * So basically we start by looking for longest sequence without duplicate characters.
 * In this case we start with l = 0, and right is going to go with for loop.
 * We use a hashset since look up time is constant, and we check if there is duplicates in hashset.
 * If there is, we delete the left portion of the set, and increase left by 1.
 * Then we insert value to the right. We calculate result with right minus left + 1 to get the window size
 * and then we just return it.
 *
 *
 *
 *
 * */


int lengthLongestSubstring(std::string s) {
  int l = 0;
  int res = 0;
  std::unordered_set<char> mySet;
  for (int r = 0; r < s.length(); r++) {
    while (mySet.count(s[r])) {
      mySet.erase(s[l]);
      l+=1;
    }
    mySet.insert(s[r]);
    res = std::max(res,r-l+1);
  }
  return res;
}

int main() {
  std::string s = "abcabbfrancisco";
  int result = lengthLongestSubstring(s);
  std::cout << result;
}
