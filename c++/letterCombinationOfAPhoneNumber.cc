class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return vector<string>{};
        string temp;
        vector<string> ret;
        dfs(ret, temp, digits, 0);
        return ret;
    }

    void dfs(vector<string> & ret, string &temp, string &digits, int size) {
        if (temp.size() == digits.size()) {
            ret.push_back(temp);
            return;
        }
        int count = 3;
        int bias = 47 + (digits[size]-50) * 2;
        if (digits[size] == '7') {
            count = 4;
        }
        if (digits[size] == '8') {
            bias += 1;
        }
        if (digits[size] == '9') {
            bias += 1;
            count = 4;
        }
        for (int i = 0; i < count; ++i) {
            temp.push_back(static_cast<char>(digits[size]+bias+i));
            size += 1;
            dfs(ret, temp, digits, size);
            size -=1;
            temp.erase(temp.end()-1);
        }
        return;
    }
};