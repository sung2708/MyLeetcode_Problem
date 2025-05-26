class Solution {
public:
  string reverseWords(string s) {
    string sol;
    if (s[0] == ' ') {
      s[0] = '\b';
    }
    if (s[s.length() - 1] == ' ') {
      s[s.length() - 1] = '\b';
    }

    for (int i = s.length() - 1; i >= 0; i--) {
      sol += s[i];
    }
    return sol;
  }
};
