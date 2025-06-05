class Solution {
public:
  int snakesAndLadders(vector<vector<int>> &board) {
    int n = board.size();

    // Helper to convert square number to (row, col)
    auto getRC = [&](int s) {
      int quot = (s - 1) / n;
      int rem = (s - 1) % n;
      int row = n - 1 - quot;
      int col = (quot % 2 == 0) ? rem : n - 1 - rem;
      return make_pair(row, col);
    };

    queue<int> q;
    vector<bool> visited(n * n + 1, false);

    q.push(1);
    visited[1] = true;
    int moves = 0;

    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        int curr = q.front();
        q.pop();
        if (curr == n * n)
          return moves;

        for (int i = 1; i <= 6; ++i) {
          int next = curr + i;
          if (next > n * n)
            continue;
          auto [r, c] = getRC(next);
          if (board[r][c] != -1) {
            next = board[r][c];
          }
          if (!visited[next]) {
            visited[next] = true;
            q.push(next);
          }
        }
      }
      ++moves;
    }

    return -1;
  }
};
