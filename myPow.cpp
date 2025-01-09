class Solution {
public:
  double myPow(double x, int n) {

    long exp = n;
    double res = 1.0;

    if (exp < 0) {
      exp = -exp;
      x = 1 / x;
    }

    while (exp > 0) {
      if (exp % 2 == 1) {
        res *= x;
      }
      x *= x;
      exp /= 2;
    }
    return res;
  }
};
