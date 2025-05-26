class Solution {
public:
  int maxRemoval(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size(), m = queries.size();
    vector<int> ans(m);
    vector<int> prefix(n + 1);

    sort(nums.begin(), nums.end());

    for (int i = 1; i <= n; i++) {
      prefix[i] = prefix[i - 1] + nums[i - 1];
    }

    for (int i = 0; i < m; i++) {
      int l = queries[i][0], r = queries[i][1];
      int low = 0, high = n, mid;
      while (low < high) {
        mid = low + (high - low) / 2;
        if (prefix[mid] <= r) {
          low = mid + 1;
        } else {
          high = mid;
        }
      }
      ans[i] = low - 1;
    }

    return ans;
  }
};
