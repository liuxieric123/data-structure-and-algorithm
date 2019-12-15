class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set_middle_ret;
        for (int ret = n; ret != 1;ret = transform(ret)) {
            if(set_middle_ret.find(ret) != set_middle_ret.end()) return false;
            else set_middle_ret.insert(ret);
        }
        return true;
    }

     bool isHappy1(int n) {
        int fast = n;
        int slow = n;
        while(true) {
            fast = transform(transform(fast));
            slow = transform(slow);
            if (fast == 1) return true;
            if (fast == slow) return false;
        }
    }

    int transform(int n) {
        int sum = 0;
        while(n != 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};