class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int size_s = s.size();
        int size_p = p.size();
        if (size_p == 0 || size_s == 0 || size_p > size_s) return {};
        unordered_map<char, int> map_c;
        for (int j = 0; j < size_p; ++j) {
            if (map_c.find(p[j]) == map_c.end())
                map_c[p[j]] = 1;
            else 
                ++map_c[p[j]];
        }
        vector<int> ret;
        for (int i = 0; i <= size_s - size_p; ++i) {
            if(dfs(size_p, i, map_c, s))
                ret.push_back(i);
        }
        return ret;
    }

    bool dfs(int count, int start, unordered_map<char, int> &map_c, string &s) {
        if (count == 0) return true;
        if (map_c.find(s[start]) == map_c.end()) return false;
        if (map_c[s[start]] == 0) return false;
        --map_c[s[start]];
        bool temp = dfs(--count, start+1, map_c, s);
        ++map_c[s[start]];
        return temp;
    }

     vector<int> findAnagrams1(string s, string p) {
        int size_s = s.size();
        int size_p = p.size();
        if (size_s == 0 || size_p == 0 || size_p > size_s) return {};
        int s_count[26];
        int p_count[26];
        for (int i = 0; i < 26; ++i) {
            s_count[i] = 0;
            p_count[i] = 0;
        }
        for (int i = 0; i < size_p; ++i) {
            ++s_count[s[i] - 'a'];
            ++p_count[p[i] - 'a'];
        }
        vector<int> ret;
        for (int i = size_p; i < size_s; ++i) {
            if (equal(s_count, s_count+26, p_count))
                ret.push_back(i - size_p);
            --s_count[s[i-size_p] - 'a'];
            ++s_count[s[i] - 'a'];
        }
        if (equal(s_count, s_count+26, p_count))
            ret.push_back(size_s - size_p);
        return ret;
    }
};