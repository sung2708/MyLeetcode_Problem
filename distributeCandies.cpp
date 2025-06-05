class Solution {
public:
  long long comb(int n, int k) {
    if (n < 0 || k < 0 || n < k)
      return 0;
    return 1LL * n * (n - 1) / 2;
  }

  long long distributeCandies(int n, int limit) {
    long long res = comb(n + 2, 2);

    for (int i = 0; i < 3; ++i) {
      res -= comb(n - (limit + 1) + 2, 2);
    }

    for (int i = 0; i < 3; ++i) {
      for (int j = i + 1; j < 3; ++j) {
        res += comb(n - 2 * (limit + 1) + 2, 2);
      }
    }

    res -= comb(n - 3 * (limit + 1) + 2, 2);

    return res;
  }
};
