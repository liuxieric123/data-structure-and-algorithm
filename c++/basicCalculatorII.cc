class Solution {
public:
    int calculate(string s) {
        int sum = 0, part = 0;
        char op = '+';
        int size = s.size();
        int pos = 0;
        
        while(pos < size) {
            while(pos < size && s[pos] == ' ') ++pos;
            int num = 0;
            while(pos < size && s[pos] >= '0' && s[pos] <= '9') {
                num = num * 10 + (s[pos] - '0');
                ++pos;
            }
            if (op == '+') {
                sum += part;
                part = num;
            } else if (op == '-') {
                sum += part;
                part = -num;
            } else if (op == '*') {
                part *= num;
            } else if (op == '/') {
                part /= num;
            }
            while(pos < size && s[pos] == ' ') ++pos;
            op = s[pos++];
        }
        return part + sum;
        

    }

};