class Solution {
public:
  int colorTheGrid(int m, int n) {
    int mod = 1e9 + 7;
    vector<int> dp(1 << (2 * m), 0);
    vector<int> new_dp(1 << (2 * m), 0);
    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < (1 << (2 * m)); ++j) {
        if (dp[j] == 0)
          continue;
        for (int k = 0; k < (1 << (2 * m)); ++k) {
          if ((j & k) == 0 && isValid(k, m)) {
            new_dp[k] = (new_dp[k] + dp[j]) % mod;
          }
        }
      }
      dp.swap(new_dp);
      fill(new_dp.begin(), new_dp.end(), 0);
    }

    long long ans = 0;
    for (int j = 0; j < (1 << (2 * m)); ++j) {
      ans = (ans + dp[j]) % mod;
    }
    return ans;
  }
};
