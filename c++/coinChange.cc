class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        int states[size][amount+1];
        for (int i = 0; i <= amount; ++i) {
            if (i % coins[0] == 0) states[0][i] = i / coins[0];
            else states[0][i] = INT_MAX;
        }
        for (int i = 1; i < size; ++i) {
            states[i][0] = 0;
            for (int j = 1; j <= amount; ++j) {
                int up = states[i-1][j];
                int left;
                if (j-coins[i] >= 0 && states[i][j-coins[i]] != INT_MAX) {
                    left = states[i][j-coins[i]] + 1;
                } else {
                    left = INT_MAX;
                }
                states[i][j] = min(up, left);
            }
        }
        return states[size-1][amount] == INT_MAX ? -1 : states[size-1][amount];
    }

    int coinChange1(vector<int>& coins, int amount) {
        int size = coins.size();
        int states[amount+1];
        for (int i = 0; i <= amount; ++i) {
            if (i % coins[0] == 0) states[i] = i / coins[0];
            else states[i] = INT_MAX;
        }
        for (int i = 1; i < size; ++i) {
            for (int j = coins[i]; j <=amount; ++j) {
                int up = states[j];
                int left;
                if (states[j-coins[i]] != INT_MAX) {
                    left = states[j-coins[i]] + 1;
                } else {
                    left = INT_MAX;
                }
                states[j] = min(up, left);
            }
        }
        return states[amount] == INT_MAX ? -1 : states[amount];
    }
};