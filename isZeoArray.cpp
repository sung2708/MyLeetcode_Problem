class Solution {
public:
  bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
    int n = queries.size();
    vector<int> deltaArr(n + 1, 0);

    for (auto x : queries) {
      int l = x[0];
      int r = x[1];

      deltaArr[l] += 1;
      deltaArr[r + 1] -= 1;
    }
    vector<int> operationCounts;
    int currentOperations = 0;
    for (int delta : deltaArr) {
      currentOperations += delta;
      operationCounts.push_back(currentOperations);
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (operationCounts[i] < nums[i]) {
        return false;
      }
    }
    return true;
  }
};
