class Solution {
public:
  int maxCandies(vector<int> &status, vector<int> &candies,
                 vector<vector<int>> &keys, vector<vector<int>> &containedBoxes,
                 vector<int> &initialBoxes) {
    int n = status.size();
    vector<bool> hasKey(n, false);
    vector<bool> boxAvailable(n, false);
    vector<bool> visited(n, false);
    queue<int> q;
    int totalCandies = 0;

    // Mark all initially available boxes
    for (int box : initialBoxes) {
      boxAvailable[box] = true;
    }

    // Keep trying to open boxes as long as we make progress
    bool progress = true;
    while (progress) {
      progress = false;

      for (int i = 0; i < n; ++i) {
        // Can open the box if we have it AND either it’s open or we have the
        // key
        if (boxAvailable[i] && !visited[i] && (status[i] == 1 || hasKey[i])) {
          visited[i] = true;
          progress = true;
          totalCandies += candies[i];

          // Gain new keys
          for (int key : keys[i]) {
            hasKey[key] = true;
          }

          // Gain new boxes
          for (int newBox : containedBoxes[i]) {
            boxAvailable[newBox] = true;
          }
        }
      }
    }

    return totalCandies;
  }
};
