class Solution {
public:
  vector<int> findWordsContaining(vector<string> &words, char x) {
    vector<int> sol;

    for (int i = 0; i < words.size(); i++) {
      if (words[i].find(x) != std::string::npos) {
        sol.push_back(i);
      }
    }
    return sol;
  }
};
