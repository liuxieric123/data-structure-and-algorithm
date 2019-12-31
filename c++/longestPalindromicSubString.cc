class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size == 0) return "";
        int len = 0;
        int start = size - 1;
        bool d[size][size];
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                d[i][j] = false;
            }
        }
        for (int i = size - 1; i >= 0; --i) {
            for (int j = i; j < size; ++j) {
                if (i == j) d[i][j] = true;
                else if (i+1 == j && s[i] == s[j]) d[i][j] = true;
                else if (s[i] == s[j] && d[i+1][j-1]) d[i][j] = true;

                if (d[i][j] && (j - i + 1) > len) {
                    len = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, len);
    }
};