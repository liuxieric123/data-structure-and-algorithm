class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> total;
        int size = cost.size();
        total.push_back(cost[0]);
        total.push_back(cost[1]);
        for (int i = 2; i < size; ++i) {
            total.push_back(min(total[i-1]+cost[i], total[i-2]+cost[i]));
        }
        return total[size - 1] > total[size - 2] ? total[size-2] : total[size-1];
    }
};