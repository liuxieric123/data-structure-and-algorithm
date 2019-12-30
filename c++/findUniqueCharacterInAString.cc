class Solution {
public:
    int firstUniqChar(string s) {
        int size = s.size();
        if (size == 0) return -1;
        int count[26];
        for (int i = 0; i < 26; ++i) {
            count[i] = 0;
        }
        for (int i = 0; i < size; ++i) {
            ++count[s[i]-'a'];
        }
        for (int i = 0; i < size; ++i) {
            if (count[s[i]-'a'] == 1)
                return i;
        }
        return -1;
    }
};