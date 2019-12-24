class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size == 0 || size == 1) return 0;
        int profit = 0;
        for (int i = 0; i < size - 1; ++i) {
            if (prices[i] < prices[i+1])
                profit += (prices[i+1]-prices[i]);
        }
        return profit;
    }
};