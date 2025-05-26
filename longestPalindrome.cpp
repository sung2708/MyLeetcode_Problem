class Solution {
public:
  int longestPalindrome(vector<string> &words) {
    unordered_map<string, int> count;
    int result = 0;
    bool hasOdd = false;

    for (const string &word : words) {
      count[word]++;
    }

    for (const auto &[word, cnt] : count) {
      string revWord = string(word.rbegin(), word.rend());
      if (word == revWord) {
        // Palindrome word
        result += (cnt / 2) * 2; // Add pairs of palindromes
        if (cnt % 2 == 1) {
          hasOdd = true; // At least one odd count
        }
      } else if (count.find(revWord) != count.end()) {
        // Non-palindrome word with its reverse present
        result += min(cnt, count[revWord]) * 2; // Add pairs of non-palindromes
      }
    }

    return result +
           (hasOdd ? 2 : 0); // Add 2 if there's at least one odd palindrome
  }
};
