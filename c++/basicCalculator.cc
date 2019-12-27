class Solution {
public:
    int calculate(string s) {
        stack<int> number;
        stack<char> oper;
        int size = s.size();
        int ret = 0;
        char op = '+';
        int num = 0;
        for (int i = 0; i < size; ++i) {
            if (s[i] <= '9' && s[i] >= '0') {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '+' || s[i] == '-') {
                if (op == '-') num = -num;
                ret += num;
                op = s[i];
                num = 0;
            } else if (s[i] == '(') {
                oper.push(op);
                number.push(ret);
                ret = 0;
                op = '+';
            } else if (s[i] == ')') {
                if (op == '-') num = -num;
                ret += num;
                op = oper.top();
                oper.pop();
                num = ret;
                ret = number.top();
                number.pop();
            }
        }
        if (op == '-') num = -num;
        return ret + num;
    }
};