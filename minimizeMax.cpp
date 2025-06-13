class Solution {
public:
  int minimizeMax(vector<int> &nums, int p) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int left = 0, right = nums[n - 1] - nums[0];

    while (left < right) {
      int mid = left + (right - left) / 2;
      int pairs = 0;
      for (int i = 1; i < n && pairs < p; i++) {
        if (nums[i] - nums[i - 1] <= mid) {
          pairs++;
          i++; // Skip the next element as it's already paired
        }
      }
      if (pairs >= p) {
        right = mid; // Try for a smaller maximum difference
      } else {
        left = mid + 1; // Increase the minimum possible maximum difference
      }
    }

    return left;
  }
};
