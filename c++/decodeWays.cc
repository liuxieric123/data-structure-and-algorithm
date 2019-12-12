class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        int states[size+1];
        states[0] = 1;
        for (int i = 0; i < size; ++i) {
            if (i == 0) {
                if (s[0] == '0') return 0;
                states[i+1] = 1;
            }
            if (i+1 < size && s[i+1] == '0') {
                if (i+2 < size && s[i+2] == '0') return 0;
                if (s[i] > '2') return 0; 
                states[i+1] = states[i];
                states[i+2] = states[i];
                ++i;
                continue;
            }
            if (i-1 >= 0) {
                if (s[i-1] == '1' || (s[i-1] == '2' && (s[i] < '7'))) {
                    states[i+1] = states[i] + states[i-1];
                } else {
                    states[i+1] = states[i];
                }
            } 
        }
        return states[size];
    }
};