class Solution {
public:
  int maximumUniqueSubarray(vector<int> &nums) {
    unordered_set<int> seen;
    int l = 0, r = 0;
    int sum = 0, maxSum = 0;

    while (r < nums.size()) {
      if (seen.find(nums[r]) == seen.end()) {
        seen.insert(nums[r]);
        sum += nums[r];
        maxSum = max(maxSum, sum);
        r++;
      } else {
        seen.erase(nums[l]);
        sum -= nums[l];
        l++;
      }
    }
    return maxSum;
  }
};
