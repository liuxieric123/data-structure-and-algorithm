class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int maxP = 0, buy = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (buy > prices[i]) buy = prices[i];
            else maxP = max(maxP, prices[i] - buy); 
        }
        return maxP;
    }
};