/*
 * A Trie (Prefix Tree) stores words one character at a time. Each node
 * represents a single character and contains a hash map (`children`) that
 * maps a character to the next TrieNode. Starting from the root, we follow
 * the path for each character in the word. If a character's node does not
 * exist, we create it. After inserting the last character, we mark that
 * node with `endOfWord = true` to indicate a complete word ends there.
 * Searching works the same way: we traverse character by character. If
 * `find(c)` returns `end()`, the character doesn't exist, so the word (or
 * prefix) isn't in the trie. If we successfully reach the last character,
 * `search()` checks `endOfWord` to ensure it's a complete word, while
 * `startsWith()` only cares that the path exists.
 */

class TrieNode {
  public:
    unordered_map<char,TrieNode*> children;
    bool endOfWord = false;
};


class PrefixTree {
  TrieNode* root;

  public:
  PrefixTree() {
    root = new TrieNode();
  }

  void insert(string word) {
    TrieNode* cur = root;
    for (char c : word) {
      if (cur->children.find(c) == cur->children.end()) {
        cur->children[c] = new TrieNode();
      }
      cur = cur->children[c];
    }
    cur->endOfWord = true;
  }

  bool search(string word) {
    TrieNode* cur = root;
    for (char c : word) {
      if (cur->children.find(c) == cur->children.end()) {
        return false;
      }
      cur = cur->children[c];
    }
    return cur->endOfWord;

  }

  bool startsWith(string prefix) {
    TrieNode* cur = root;
    for (char c : prefix) {
      if (cur->children.find(c) == cur->children.end()) {
        return false;
      }
      cur = cur->children[c];
    }
    return true;
  }
};
