class Solution {
public:
  string robotWithString(string s) {
    string result;
    string stack;
    int n = s.size();
    vector<int> next(
        n + 1, 26); // next[i] is the smallest character from s[i] to s[n-1]

    // Precompute the next smallest character
    for (int i = n - 1; i >= 0; --i) {
      next[i] = min(next[i + 1], s[i] - 'a');
    }

    for (int i = 0; i < n; ++i) {
      while (!stack.empty() && (stack.back() - 'a' <= next[i])) {
        result += stack.back();
        stack.pop_back();
      }
      stack.push_back(s[i]);
    }

    while (!stack.empty()) {
      result += stack.back();
      stack.pop_back();
    }

    return result;
  }
};
