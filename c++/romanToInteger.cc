class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> num{{'I', 1}, {'V', 5}, 
        {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int size = s.size();
        if (size == 0) return 0;
        int right = num[s[size - 1]];
        int ret = right;
        for (int i = size - 2; i >= 0; --i) {
            int left = num[s[i]];
            if (right <= left) ret += left;
            else ret -= left;
            right = left;
        }
        return ret;
    }
    int romanToInt1(string s) {
        unordered_map<char, int> num{{'I', 1}, {'V', 5}, 
        {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int size = s.size();
        if (size == 0) return 0;
        int ret = 0;
        int neg = 0;
        for (int i = 0; i < size-1; ++i) {
            if (num[s[i]] < num[s[i+1]]) 
                neg -=num[s[i]];
            else 
                ret += num[s[i]];
        }
        ret += num[s.back()];
        return ret + neg;
    }
};