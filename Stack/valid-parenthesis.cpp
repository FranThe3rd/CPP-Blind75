#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>

/* Ok Valid Parenthesis, this is a LeetCode problem that checks if a string input is valid.
 * A string is valid if:
 * - Open brackets must be closed by the same type of bracket
 * - Brackets must be closed in the correct order (last opened must close first)
 * "(" is an opening bracket, and ")" is a closing bracket.
 * We use a stack for this because it follows LIFO (Last In First Out).
 * That means the last bracket we saw is the first one we need to match.
 * We also use a hashmap (unordered_map) that maps closing brackets to opening brackets.
 * This lets us quickly check what each closing bracket should match with.
 * As we iterate through the string:
 * - If we see a closing bracket, we check the top of the stack.
 *   - If the stack is empty, that means there is nothing to match it with → invalid
 *   - If the top of the stack matches the correct opening bracket, we pop it
 *   - Otherwise, it’s the wrong type → invalid
 * - If we see an opening bracket, we push it onto the stack
 * At the end, if the stack is empty, everything matched correctly → valid string
 * It will return 1, since its C++, and one stands for true.
 */

bool isValid(std::string s) {
  std::stack<char> stack;
  std::unordered_map<char, char> closeToOpen = {
    {')', '('},
    {']', '['},
    {'}', '{'}
  };

  for (char c : s) {
    if (closeToOpen.count(c)) { // This is equivalent to python "if c in close_to_open:"
      if (!stack.empty() && stack.top() == closeToOpen[c]) { 
        stack.pop();
      } else {
        return false;
      }
    } else {
      stack.push(c);
    }
  }
  return stack.empty();
}


int main() {
  std::string s = "()[]{}";
  bool result = isValid(s);
  std::cout<< result;
  return 0;
}
