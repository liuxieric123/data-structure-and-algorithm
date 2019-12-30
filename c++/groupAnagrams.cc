class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        if (size == 0) return vector<vector<string>> {};
        unordered_map<string, vector<string>> key_vector;
        for (auto str: strs) {
            string tmp = getKey(str);
            if (key_vector.find(tmp) == key_vector.end()) {
                vector<string> vec_string{str};
                key_vector[tmp] = vec_string;
            } else {
                key_vector[tmp].push_back(str);
            }
        }
        vector<vector<string>> ret;
        for (auto pair: key_vector) {
            ret.push_back(pair.second);
        }
        return ret;
    }

    string getKey(string str) {
        int count[26];
        for (int i = 0; i < 26; ++i) {
            count[i] = 0;
        }
        for (auto c : str) {
            ++count[c-'a'];
        }
        string tmp;
        for (int i = 0; i < 26; ++i) {
            tmp.push_back(count[i]);
        }
        return tmp;
    }

    vector<vector<string>> groupAnagrams1(vector<string>& strs) {
        int size = strs.size();
        if (size == 0) return vector<vector<string>> {};
        unordered_map<string, vector<string>> key_vector;
        for (auto str: strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            if (key_vector.find(tmp) == key_vector.end()) {
                key_vector[tmp] = vector<string>{str};
            } else {
                key_vector[tmp].push_back(str);
            }
        }
        vector<vector<string>> ret;
        for (auto pair: key_vector) {
            ret.push_back(pair.second);
        }
        return ret;
    }
};