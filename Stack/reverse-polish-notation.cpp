#include <iostream>
#include <stack>



/*
 * You are given an array of strings tokens that represents a valid arithmetic expression in Reverse Polish Notation.
 * Return the integer that represents the evaluation of the expression.
 * The operands may be integers or the results of other operations.
 * The operators include '+', '-', '*', and '/'.
 * Assume that division between integers always truncates toward zero.
 * Example 1:
 * Input: tokens = ["1","2","+","3","*","4","-"]
 * Output: 5
 * Explanation: ((1 + 2) * 3) - 4 = 5
 *
 * So since this is c++ you have to assign the value of a and b to the most recent values of the stack and pop it since
 * in c++ those values are void by default, unlike python.
 * Then push into your own stack.
 * */

#include <vector>
#include <string>
#include <stack>

int evalRPN(std::vector<std::string>& tokens) {
  std::stack<int> st;

  for (const std::string& c : tokens) {
    if (c == "+") {
      int a = st.top(); st.pop();
      int b = st.top(); st.pop();
      st.push(b + a);
    }
    else if (c == "*") {
      int a = st.top(); st.pop();
      int b = st.top(); st.pop();
      st.push(b * a);
    }
    else if (c == "-") {
      int a = st.top(); st.pop();
      int b = st.top(); st.pop();
      st.push(b - a);
    }
    else if (c == "/") {
      int a = st.top(); st.pop();
      int b = st.top(); st.pop();
      st.push(b / a); 
    }
    else {
      st.push(std::stoi(c)); // This converts it into a int
    }
  }

  return st.top();
}


int main() {
  std::vector<std::string> tokens = {"1","2","+","3","*","4","-"};
  std::stack<int> result = evalRPN(tokens);
  for (num : result) {
    std::cout << num;
  }
}
