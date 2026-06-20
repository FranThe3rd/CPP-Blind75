
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;


/* Group Anagrams, you have to see which word has the same letters in them.
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * So you start by iterating through the vector of strings.
 * Then you create an array of zero's, 26 of them since they correspond to the alphabet
 * Then you iterate through each letter in the words, with another for loop, and you subtract
 * the letter minus the letter "a" which would equal to the index of that letter because of ascii values.
 * You add one to it, and it will go to the count array for example [0,1,0,0...]
 * Since you can not have an array as key, you create a string key, iterate through the count array
 * and then key will equal a string version of coun array seperated by a "," for example "0,1,0,0"
 * The group hashmap will add the word that has the same key for example "0,1,0,0" : [eat,ate]
 * Then iterate through the hashmap like a pair, and add the words to the results array, and then
 * return the result.
 */



vector<vector<string>> groupAnagrams(vector<string> strs) {
  unordered_map<string, vector<string>> groups;
  for (const string& word : strs) {
    vector<int> count(26, 0);
    for (char letter : word) {
      count[letter - 'a'] += 1;
    }
    string key;
    for (int num : count) {
      key += to_string(num) + ",";
    }
    groups[key].push_back(word);
  }
  vector<vector<string>> result;
  for (const auto& [key, words] : groups) {
    result.push_back(words);
  }
  return result;
}




int main() {
  vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
  vector<vector<string>> result = groupAnagrams(strs);
  for (const auto& group : result) {
    for (const auto& word : group) cout << word << " ";
    cout << "\n";
  }
}
