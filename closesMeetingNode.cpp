class Solution {
public:
  int closestMeetingNode(vector<int> &edges, int node1, int node2) {
    int n = edges.size();
    vector<int> dist1(n, -1), dist2(n, -1);
    queue<int> q1, q2;
    // BFS for node1
    q1.push(node1);
    dist1[node1] = 0;
    while (!q1.empty()) {
      int curr = q1.front();
      q1.pop();
      int next = edges[curr];
      if (next != -1 && dist1[next] == -1) {
        dist1[next] = dist1[curr] + 1;
        q1.push(next);
      }
    }
    // BFS for node2
    q2.push(node2);
    dist2[node2] = 0;
    while (!q2.empty()) {
      int curr = q2.front();
      q2.pop();
      int next = edges[curr];
      if (next != -1 && dist2[next] == -1) {
        dist2[next] = dist2[curr] + 1;
        q2.push(next);
      }
    }
    // Find the closest meeting node
    int minDist = INT_MAX, closestNode = -1;
    for (int i = 0; i < n; ++i) {
      if (dist1[i] != -1 && dist2[i] != -1) {
        int maxDist = max(dist1[i], dist2[i]);
        if (maxDist < minDist) {
          minDist = maxDist;
          closestNode = i;
        }
      }
    }
    return closestNode;
  }
};
