class Solution {
public:
  bool containsDuplicate(std::vector<int> &nums) {
    std::unordered_map<int, int> freq;
    for (int num : nums) {
      if (++freq[num] > 1)
        return true;
    }
    return false;
  }
};
