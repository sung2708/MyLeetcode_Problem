class Solution {
public:
  int remove(string &s, char a, char b, int score) {
    stack<char> st;
    int total = 0;
    for (char c : s) {
      if (!st.empty() && st.top() == a && c == b) {
        st.pop();
        total += score;
      } else {
        st.push(c);
      }
    }

    // Rebuild string from stack
    s = "";
    while (!st.empty()) {
      s += st.top();
      st.pop();
    }
    reverse(s.begin(), s.end()); // restore original order
    return total;
  }

  int maximumGain(string s, int x, int y) {
    int total = 0;

    // Prioritize higher score
    if (x > y) {
      total += remove(s, 'a', 'b', x);
      total += remove(s, 'b', 'a', y);
    } else {
      total += remove(s, 'b', 'a', y);
      total += remove(s, 'a', 'b', x);
    }

    return total;
  }
};
