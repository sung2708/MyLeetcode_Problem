class Solution {
private:
  void dfs(int current, int n, vector<int> &result) {
    if (current > n)
      return;
    result.push_back(current);
    for (int i = 0; i <= 9; ++i) {
      int next = current * 10 + i;
      if (next > n)
        break;
      dfs(next, n, result);
    }
  }

public:
  vector<int> lexicalOrder(int n) {
    vector<int> result;
    for (int i = 1; i <= 9; ++i) {
      dfs(i, n, result);
    }
    return result;
  }
};
