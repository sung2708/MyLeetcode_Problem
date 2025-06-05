class Solution {
public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    vector<int> parent(26);
    for (int i = 0; i < 26; ++i) {
      parent[i] = i; // Initialize each character to be its own parent
    }

    // Union-Find to connect characters
    for (int i = 0; i < s1.size(); ++i) {
      int root1 = find(parent, s1[i] - 'a');
      int root2 = find(parent, s2[i] - 'a');
      if (root1 != root2) {
        parent[max(root1, root2)] =
            min(root1, root2); // Union by lexicographically smaller character
      }
    }

    // Build the result string
    string result;
    for (char c : baseStr) {
      result += char(find(parent, c - 'a') + 'a');
    }

    return result;
  }

private:
  int find(vector<int> &parent, int x) {
    if (parent[x] != x) {
      parent[x] = find(parent, parent[x]); // Path compression
    }
    return parent[x];
  }
};
