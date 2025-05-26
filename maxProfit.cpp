class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int min_Price = prices[0];
    int max_Profit = 0;

    for (int i = 1; i < prices.size(); i++) {
      min_Price = min(min_Price, prices[i]);
      max_Profit = max(max_Profit, prices[i] - min_Price);
    }
    return max_Profit;
  }
};
