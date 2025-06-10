
class Solution {
public:
  int maxDifference(std::string s) {
    std::unordered_map<char, int> freq;

    for (char c : s) {
      freq[c]++;
    }

    std::vector<int> oddFreqs;
    std::vector<int> evenFreqs;

    for (const auto &entry : freq) {
      if (entry.second % 2 == 1)
        oddFreqs.push_back(entry.second);
      else
        evenFreqs.push_back(entry.second);
    }

    int maxDiff = INT_MIN;
    for (int odd : oddFreqs) {
      for (int even : evenFreqs) {
        maxDiff = std::max(maxDiff, odd - even);
      }
    }

    return (maxDiff == INT_MIN) ? 0 : maxDiff;
  }
};
