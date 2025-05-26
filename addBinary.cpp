class Solution {
public:
  string addBinary(string a, string b) {
    int n = a.size();
    int m = b.size();
    int carry = 0;
    string ans = "";
    for (int i = n - 1, j = m - 1; i >= 0 || j >= 0; i--, j--) {
      int sum = carry;
      sum += (i >= 0) ? a[i] - '0' : 0;
      sum += (j >= 0) ? b[j] - '0' : 0;
      ans += to_string(sum % 2);
      carry = sum / 2;
    }

    if (carry) {
      ans += to_string(carry);
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};

/*
class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();
        int carry = 0;
        string ans = "";

        for (int i = n - 1, j = m - 1; i >= 0 || j >= 0 || carry; i--, j--) {
            int sum = carry;
            if (i >= 0) sum += a[i] - '0';
            if (j >= 0) sum += b[j] - '0';

            ans += (sum % 2) + '0';
            carry = sum / 2;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

*/
