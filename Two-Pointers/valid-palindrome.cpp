#include <string>
#include <cctype>
#include <iostream>


/* 
 * We return either true or false if a string is a palindrome,
 * we use a two pointer solution where l is the beginning and r is the end of the string
 * We keep check while l < r, and if its not alphanumeric we skip it in the if statements.
 * Either ways we check if they are equal to each other, if they are not we return false.
 *
 *
 *
 *
 *
 * */

bool isPalindrome(std::string s) {
  int l = 0;
  int r = s.length() - 1;

  while (l < r) {
    if (!std::isalnum(s[l])) {
      l++;
    }
    else if (!std::isalnum(s[r])) {
      r--;
    }
    else if (std::tolower(s[l]) != std::tolower(s[r])) {
      return false;
    }
    else {
      l++;
      r--;
    }
  }

  return true;
}


int main() {

  std::string s = "racecar";
  bool result = isPalindrome(s);
  std::cout << result;

}
