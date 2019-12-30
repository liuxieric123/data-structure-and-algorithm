class Solution {
public:
    string minWindow(string s, string t) {
        int size_s = s.size();
        int size_t = t.size();
        if (size_s == 0 || size_t == 0 || size_s < size_t) return "";
        int count_c[256] = {0};
        int left = 0, right = 0, count = size_t, len = INT_MAX, start = 0;
        for (int i = 0; i < size_t; ++i) {
            ++count_c[t[i]];
        }
        for (; right < size_s; ++right ) {
            if (count_c[s[right]] > 0) --count;
            --count_c[s[right]];
            while(count == 0) {
                if (right - left + 1 < len) {
                    start = left;
                    len = right - left + 1;
                }
                
                ++count_c[s[left]];
                if (count_c[s[left]] > 0) ++count;
                ++left;
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }

};