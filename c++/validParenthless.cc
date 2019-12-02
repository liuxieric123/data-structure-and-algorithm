#include <stack>
#include <string>

using std::string;
using std::stack;

class Solution {
    bool isValid(string s) {
        if (s == "") return true;
        stack<char> stack_c;
        for (auto & c: s) {
            if (c == '(') {
                stack_c.push(c);
                stack_c.push(')');
            }
            else if (c == '{') {
                stack_c.push('{');
                stack_c.push('}');
            }
            else if (c == '[') {
                stack_c.push('[');
                stack_c.push(']');
            }
            else if (stack_c.size() == 0) return false;
            else {
                char temp = stack_c.top();
                stack_c.pop();
                stack_c.pop();
                if (temp != c) return false;
            }
        }
        return stack_c.size() == 0;
    }
};