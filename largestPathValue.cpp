class Solution {
public:
  int largestPathValue(string colors, vector<vector<int>> &edges) {
    int n = colors.size();
    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);
    vector<vector<int>> colorCount(n, vector<int>(26, 0));

    for (const auto &edge : edges) {
      int u = edge[0], v = edge[1];
      graph[u].push_back(v);
      indegree[v]++;
    }

    queue<int> q;

    for (int i = 0; i < n; ++i) {
      if (indegree[i] == 0) {
        q.push(i);
        colorCount[i][colors[i] - 'a'] = 1;
      }
    }

    int result = 0;
    int visited = 0;

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      visited++;

      for (int v : graph[u]) {
        for (int c = 0; c < 26; ++c) {
          // propagate the color counts from u to v
          colorCount[v][c] = max(colorCount[v][c], colorCount[u][c]);
        }

        indegree[v]--;
        if (indegree[v] == 0) {
          // after collecting all counts, we can now add the color of node v
          colorCount[v][colors[v] - 'a']++;
          q.push(v);
        }
      }

      result =
          max(result, *max_element(colorCount[u].begin(), colorCount[u].end()));
    }

    return visited == n ? result : -1;
  }
};
