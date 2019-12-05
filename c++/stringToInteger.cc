#include <climits>
#include <cctype>

class Solution {
public:
    int myAtoi(string str) {
        if (str.size() == 0) return 0;
        auto it = str.begin();
        while(*it == ' ') ++it;
        long ret = 0;
        bool neg = false;
        if (*it == '-' || *it == '+') {
            if (*it == '-') neg = true;
            ++it;
        }
        for (; isdigit(*it); ++it) {
            if (neg) ret = ret * 10 - (*it - '0');
            else ret = ret * 10 + (*it - '0');
            if (ret > INT_MAX) return INT_MAX;
            else if (ret < INT_MIN) return INT_MIN;
        }
        return ret;
    }
};