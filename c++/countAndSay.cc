class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return NULL;
        string res = "1";
        if (n == 1) return res;
        for (int i = 2; i <= n; ++i) {
            string temp;
            char cur = res[0];
            int count = 1;
            int size = res.size();
            for (int j = 1; j < size; ++j) {
                if (res[j] == cur) ++count;
                else {
                    temp+=to_string(count);
                    temp+=cur;
                    cur = res[j];
                    count = 1;
                }
            }
            temp+=to_string(count);
            temp+=cur;
            res = temp;
        }
        return res;
    }
};