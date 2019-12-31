class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        if (size == 0) return "";
        auto iter_first = s.begin();
        auto iter_second = s.begin();
        for(; iter_second != s.end(); ++iter_second) {
            if (*iter_second == ' ') {
                reverse(iter_first, iter_second);
                iter_first = iter_second + 1;
            }
        }
        reverse(iter_first, iter_second);
        return s;
    }
};