class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        int low = 1;
        int high = x;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if (x / mid > mid) low = mid + 1;
            else if (x / mid < mid) high = mid - 1;
            else return mid;
        }
        return high;
    }
};