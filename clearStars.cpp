class Solution {
public:
  string clearStars(string s) {
    vector<char> res; // chuỗi đang xây
    array<vector<int>, 26>
        idx; // idx[c] = list vị trí còn sống của chữ c
             // luôn tăng dần, nên pop_back() lấy vị trí phải nhất

    for (char c : s) {
      if (c != '*') {
        res.push_back(c);
        idx[c - 'a'].push_back((int)res.size() - 1);
      } else {                         // gặp '*'
        for (int t = 0; t < 26; ++t) { // tìm chữ nhỏ nhất đang còn
          if (!idx[t].empty()) {
            int pos = idx[t].back(); // vị trí phải nhất của chữ nhỏ nhất
            idx[t].pop_back();
            res[pos] = '#'; // đánh dấu đã xoá
            break;          // xử lý xong một '*'
          }
        }
      }
    }

    string ans;
    ans.reserve(res.size());
    for (char c : res)
      if (c != '#')
        ans.push_back(c);
    return ans;
  }
};
