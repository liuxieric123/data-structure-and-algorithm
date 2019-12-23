class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.size() == 0) return vector<vector<string>>{};
        vector<vector<string>> ret;
        vector<string> temp;
        dfs(s, 0, 0, temp, ret);
        return ret;
    }

    void dfs(string & s, int start, int partPos, vector<string>& temp, vector<vector<string>>& ret) {
        for (int i = 0; i < s.size() - partPos; ++i) {
            if (isPalindrome(s, start, partPos+i)) {
                temp.push_back(string(s, start, partPos-start+1+i));
                if (partPos == s.size() - 1 - i) {
                    ret.push_back(temp);
                    temp.erase(temp.end()-1);
                    return;
                }
                dfs(s, partPos+1+i, partPos+1+i, temp, ret);
                temp.erase(temp.end()-1);
            }
        }
        
    }

    bool isPalindrome(string & s, int start, int end) {
        while (end > start) {
            if (s[start] != s[end])
                return false;
            ++start;
            --end;
        }
        return true;
    }
};