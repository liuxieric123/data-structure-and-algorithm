#include <map>
#include <utility>
#include <string>

using std::string;
using std::map;
using std::pair;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> map_char;
        int count = 0;
        bool flag = false;
        for (auto c: s) {
            if (map_char.find(c) != map_char.end()) map_char[c] += 1;
            else map_char.insert(pair<char, int>(c, 1));
        }
        for (auto p : map_char) {
            if (p.second % 2 == 1) {
                count += (p.second - 1);
                flag = true;
            } else {
                count += p.second;
            }
        }
        if (flag) count += 1;
        return count;
    }
};