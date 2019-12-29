class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        if (size == 0) return s;
        int end = size - 1;
        while(s[end] == ' ') --end;
        int p = 0, q = 0;
        while(q <= end) {
            int start = p;
            while(q <= end && s[q] == ' ') ++q;
            while(q <= end && s[q] != ' ') s[p++] = s[q++];
            reverse(s.begin()+start, s.begin()+p);
            if (q <= end)
                s[p++] = ' '; 
        }
        s.erase(s.begin()+p, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};