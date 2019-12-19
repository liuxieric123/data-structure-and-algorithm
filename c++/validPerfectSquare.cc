class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 0) return 0;
        int low = 1, high = num;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if (num / mid > mid) low = mid + 1;
            else high = mid;
        }
        if (double(num) / low == double(low)) return true;
        else return false;
    }
};