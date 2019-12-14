class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int size = coins.size();
        int states[amount+1];
        for (int i = 0; i <= amount; ++i) {
            if (i == 0) states[i] = 1;
            else states[i] = 0;
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j <= amount; ++j) {
                int up = states[j];
                int left;
                if (j-coins[i] >=0)
                    left = states[j-coins[i]];
                else 
                    left = 0;
                states[j] = up + left;
            }
        }
        return states[amount];
    }
};