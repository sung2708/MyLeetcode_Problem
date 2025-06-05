class Solution {
public:
  vector<int> maxTargetNodes(vector<vector<int>> &edges1,
                             vector<vector<int>> &edges2, int k) {
    int n = edges1.size() + 1;
    int m = edges2.size() + 1;

    vector<vector<int>> tree1(n), tree2(m);
    for (auto &e : edges1) {
      tree1[e[0]].push_back(e[1]);
      tree1[e[1]].push_back(e[0]);
    }
    for (auto &e : edges2) {
      tree2[e[0]].push_back(e[1]);
      tree2[e[1]].push_back(e[0]);
    }

    vector<int> result(n);

    // Precompute reachable nodes in tree2 for each node with dist <= k-1
    vector<int> tree2Reach(m, 0);
    for (int i = 0; i < m; ++i) {
      tree2Reach[i] = bfs(tree2, i, k - 1);
    }

    // For each node in tree1
    for (int i = 0; i < n; ++i) {
      int maxReach = 0;
      int cnt1 = bfs(tree1, i, k);
      for (int j = 0; j < m; ++j) {
        maxReach = max(maxReach, cnt1 + tree2Reach[j]);
      }
      result[i] = maxReach;
    }

    return result;
  }

private:
  int bfs(vector<vector<int>> &tree, int start, int maxDist) {
    int n = tree.size();
    vector<bool> visited(n, false);
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;
    int count = 0;

    while (!q.empty()) {
      auto [node, dist] = q.front();
      q.pop();
      if (dist > maxDist)
        continue;
      count++;
      for (int nei : tree[node]) {
        if (!visited[nei]) {
          visited[nei] = true;
          q.push({nei, dist + 1});
        }
      }
    }

    return count;
  }
};
