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

     int countSubstrings1(string s) {
        int size = s.size();
        if (size == 0) return 0;
        int count = 0;
        for (int i = 0; i < size; ++i) {
            int len = expand(s, i, i);
            int len1 = expand(s, i, i+1);
            if (len > 0) count += ((len+1) / 2);
            if (len1 > 0) count += (len1 / 2);

        }
        return count;
    }

    int expand(string & s, int left, int right) {
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return right - 1 - left;
    }
};