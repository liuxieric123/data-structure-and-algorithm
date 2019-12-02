#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.size();
        for (int i = 0, j = size - 1; i < j; ++i, --j) {
            while (i < j && !isalnum(s[i])) ++i;
            while (i < j && !isalnum(s[j])) --j;
            if (i < j && tolower(s[i]) != tolower(s[j])) return false;
        }
        return true;
    }
};