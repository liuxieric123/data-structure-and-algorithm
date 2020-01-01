class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.size();
        if (size == 0) return 0;
        stack<int> st;
        int maxCount = 0;
        st.push(-1);
        for (int i = 0; i < size; ++i) {
            if (s[i] == ')' && !st.empty() && st.top() >= 0 && s[st.top()] == '(') {
                st.pop();
                maxCount = max(maxCount, i - st.top());
            } else {
                st.push(i);
            }
        }
        return maxCount;
    }
};