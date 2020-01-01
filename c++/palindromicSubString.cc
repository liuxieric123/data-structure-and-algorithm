class Solution {
public:
    int countSubstrings(string s) {
        int size = s.size();
        if (size == 0) return 0;
        bool states[size][size];
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                states[i][j] = false;
            }
        }
        int count = 0;
        for (int i = size - 1; i >=0; --i) {
            for (int j = i; j < size; ++j) {
                if (i == j) states[i][j] = true;
                else if (i+1 == j && s[i] == s[j]) states[i][j] = true;
                else if (s[i] == s[j] && states[i+1][j-1]) states[i][j] = true;

                if (states[i][j]) ++count;
            }
        }
        return count;
    }
};