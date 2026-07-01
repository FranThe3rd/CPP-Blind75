#include <iostream>
#include <vector>
#include <string>


/* Decode String List (encode/decode pattern)
 *
 * Idea:
 * We store each string as:  length + "#" + string
 * Example: "hello" -> "5#hello"
 *
 * This lets us safely store ANY string, even if it contains '#'.
 * Because we never search for words directly — we use the length.
 *
 *
 * ENCODE:
 * For each string:
 * - Convert its length to a string
 * - Append "#" as a separator
 * - Append the actual string
 *
 * Example:
 * ["hello", "world"]
 * -> "5#hello5#world"
 *
 *
 * DECODE:
 * We scan the encoded string using two pointers i and j.
 *
 * Step 1:
 * Move j until we find '#'
 * So s[i..j-1] is the length string
 *
 * Step 2:
 * Convert it:
 * length = stoi(s.substr(i, j - i))
 *
 * Step 3:
 * i = j + 1
 * Move i to start of actual word (after '#')
 *
 * Step 4:
 * j = i + length
 * Now we know exactly where the word ends
 *
 * Step 5:
 * Extract word:
 * s.substr(i, length)
 *
 * Step 6:
 * Move i = j
 * Continue to next encoded chunk
 *
 *
 * WHY THIS WORKS:
 * - '#' is just a separator
 * - length tells us EXACTLY how many characters to read
 * - so we never rely on delimiters inside the word
 */

std::string encode(std::vector<std::string>& strs) {
    std::string res;

    for (const auto& str : strs) {
        res += std::to_string(str.length()) + "#" + str;
    }

    return res;
}

std::vector<std::string> decode(std::string s) {
    std::vector<std::string> res;  // * -> "5#hello5#world"

    int i = 0;

    while (i < s.length()) {
        int j = i;

        while (s[j] != '#') {
            j++;
        }

        int length = std::stoi(s.substr(i, j - i));

        i = j + 1;
        j = i + length;

        res.push_back(s.substr(i, length));

        i = j;
    }

    return res;
}

int main() {
    std::vector<std::string> strs = {
        "hello",
        "world",
        "neet"
    };

    std::string encoded = encode(strs);

    std::cout << "Encoded: " << encoded << '\n';

    std::vector<std::string> decoded = decode(encoded);

    std::cout << "Decoded:\n";
    for (const auto& str : decoded) {
        std::cout << str << '\n';
    }

    return 0;
}
