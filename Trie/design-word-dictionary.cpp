
/*
 * This solution uses a Trie (Prefix Tree) to store words character by
 * character. Each node contains a hash map (`children`) that points to
 * the next characters and a boolean (`endOfWord`) indicating whether a
 * complete word ends at that node. Adding a word simply follows or creates
 * the path for each character. Searching is done with Depth-First Search
 * (DFS) because the '.' wildcard can represent any single character. Each
 * recursive call is responsible for matching one character of the word.
 * If the current character is '.', DFS tries every child node and returns
 * true as soon as one path successfully matches the rest of the word.
 * Otherwise, it follows the matching character if it exists. If a character
 * is missing or every wildcard path fails, it returns false.
 */

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false;
};

class WordDictionary {
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* cur = root;

        for (char c : word) {
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }

        cur->endOfWord = true;
    }

    bool dfs(TrieNode* root, string& word, int i) {
        if (i == word.size()) {
            return root->endOfWord;
        }

        char c = word[i];

        if (c == '.') {
            for (auto& [ch, node] : root->children) {
                if (dfs(node, word, i + 1)) {
                    return true;
                }
            }
        } else {
            if (root->children.find(c) != root->children.end()) {
                return dfs(root->children[c], word, i + 1);
            }
        }

        return false;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};
