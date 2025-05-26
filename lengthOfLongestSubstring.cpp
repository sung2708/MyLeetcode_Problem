class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> se;
    int max_l = 0, j = 0, i = 0;
    while (j < s.length()) {
      if (se.find(s[j]) == se.end()) {
        se.insert(s[j]);
        max_l = max(max_l, (int)se.size());
        j++;
      } else {
        se.erase(s[i]);
        i++;
      }
    }
    return max_l;
  }
};
