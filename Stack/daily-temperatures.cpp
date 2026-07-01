#include <stack>
#include <vector>
#include <iostream>
#include <utility>


/*
 *  You are given an array of integers temperatures where temperatures[i] represents the daily temperatures on the ith day.
 *  Return an array result where result[i] is the number of days after the ith day before a warmer temperature
 *  appears on a future day. If there is no day in the future where a warmer temperature will appear for the
 *  ith day, set result[i] to 0 instead.
 *  Example 1:
 *  Input: temperatures = [30,38,30,36,35,40,28]
 *  Output: [1,4,1,2,1,0,0]
 *  So we create a result array, size of the temperatures array but all of them are zeros [0,0,0...]
 *  Then we create a stack which will take a pair, which is {temperatures,index}
 *  We iterate through the for loop, and check if stack is not empty and the temperature greater than the most
 *  recent value of the stack, since its empty we add a value. Then we iterate again now we found a value greater
 *  So we pop most recent value on stack which is {30,0} and then at res[0] = 1 - 0 = 1. Since greater value is {38,1}.
 *  Then we add that pair to stack which is {38,1}. Then rinse and repeate.
 *
 *
 *
 * */

std::vector<int> dailyTemperatures(std::vector<int> temperatures) {

  std::vector<int> res(temperatures.size(),0);
  std::stack<std::pair<int,int>> stack;

  for (int i = 0; i < temperatures.size(); i++) {
    int t = temperatures[i];
    while (!stack.empty() && t > stack.top().first) {
      auto pair = stack.top();
      stack.pop();
      res[pair.second] = i - pair.second;
    }
    stack.push({t,i});
  }

  return res;

}

int main() {
  std::vector<int> temperatures = {30,38,30,36,35,40,28};
  std::vector<int> result = dailyTemperatures(temperatures);
  
  for (int num : result) {
    std::cout<<num;
  }


}
