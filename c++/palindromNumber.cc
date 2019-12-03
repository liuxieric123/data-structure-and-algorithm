#include <string>

using std::string;
using std::to_string;

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int size = s.size();
        for (int i = 0, j = size - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
};