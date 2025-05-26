class Solution {
public:
  vector<string> getLongestSubsequence(vector<string> &words,
                                       vector<int> &groups) {
    int n = words.size();
    vector<string> result;
    int maxLength = 0;

    for (int i = 0; i < n; ++i) {
      string word = words[i];
      int length = word.length();
      if (length > maxLength) {
        maxLength = length;
        result.clear();
        result.push_back(word);
      } else if (length == maxLength) {
        result.push_back(word);
      }
    }

    return result;
  }
};
