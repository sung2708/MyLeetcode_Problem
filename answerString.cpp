class Solution {
  const int base1 = 131, base2 = 137;
  const int mod1 = 1000000007, mod2 = 1000000009;
  vector<long long> pow1, pow2, hash1, hash2;

  void initHash(const string &s) {
    int n = (int)s.size();
    pow1.assign(n + 1, 1);
    pow2.assign(n + 1, 1);
    hash1.assign(n + 1, 0);
    hash2.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
      pow1[i] = (pow1[i - 1] * base1) % mod1;
      pow2[i] = (pow2[i - 1] * base2) % mod2;
      hash1[i] = (hash1[i - 1] * base1 + s[i - 1]) % mod1;
      hash2[i] = (hash2[i - 1] * base2 + s[i - 1]) % mod2;
    }
  }

  pair<long long, long long> getHash(int l, int r) {
    long long x1 =
        (hash1[r + 1] - (hash1[l] * pow1[r - l + 1]) % mod1 + mod1) % mod1;
    long long x2 =
        (hash2[r + 1] - (hash2[l] * pow2[r - l + 1]) % mod2 + mod2) % mod2;
    return {x1, x2};
  }

  int getLCP(const string &s, int a, int b) {
    int low = 0;
    int high = (int)s.size() - max(a, b);
    while (low < high) {
      int mid = (low + high + 1) / 2;
      if (getHash(a, a + mid - 1) == getHash(b, b + mid - 1))
        low = mid;
      else
        high = mid - 1;
    }
    return low;
  }

  bool isGreater(int a_start, int a_end, int b_start, int b_end,
                 const string &s) {
    int lcp = getLCP(s, a_start, b_start);
    int a_len = a_end - a_start + 1;
    int b_len = b_end - b_start + 1;
    if (lcp >= min(a_len, b_len)) {
      return a_len > b_len; // longer substring is lex greater if prefix equal
    }
    return s[a_start + lcp] > s[b_start + lcp];
  }

public:
  string answerString(string word, int numFriends) {
    int n = (int)word.size();
    initHash(word);

    vector<vector<pair<int, int>>> dp(
        n, vector<pair<int, int>>(numFriends + 1, {-1, -1}));
    vector<vector<bool>> visited(n, vector<bool>(numFriends + 1, false));

    function<pair<int, int>(int, int)> dfs = [&](int start,
                                                 int k) -> pair<int, int> {
      if (start >= n)
        return {-1, -1};
      if (k == 1)
        return {start, n - 1};
      if (visited[start][k])
        return dp[start][k];
      visited[start][k] = true;

      pair<int, int> best = {-1, -1};
      for (int cut = start; cut <= n - k; ++cut) {
        pair<int, int> firstPart = {start, cut};
        pair<int, int> restPart = dfs(cut + 1, k - 1);
        if (restPart.first == -1)
          continue;

        // candidate is max(firstPart, restPart)
        pair<int, int> candidate;
        if (isGreater(firstPart.first, firstPart.second, restPart.first,
                      restPart.second, word))
          candidate = firstPart;
        else
          candidate = restPart;

        if (best.first == -1 || isGreater(candidate.first, candidate.second,
                                          best.first, best.second, word))
          best = candidate;
      }

      dp[start][k] = best;
      return best;
    };

    pair<int, int> res = dfs(0, numFriends);
    return word.substr(res.first, res.second - res.first + 1);
  }
};
// TLE
