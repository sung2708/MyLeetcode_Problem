class Solution {
public:
  int findClosest(int x, int y, int z) {
    int distX = abs(x - z);
    int distY = abs(y - z);

    if (distX < distY) {
      return x;
    } else if (distY < distX) {
      return y;
    } else {
      return 0;
    }
  }
};
