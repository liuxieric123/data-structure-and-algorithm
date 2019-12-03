#include <set>
#include <string>
#include <algorithm>

using std::max;
using std::string;
using std::set;

class Solutio {
    public:
        int lengthOfLongestSubstring(string & s) {
            int maxLen = 0;
            int count = 0;
            set<char> set_c;
            auto ite = s.begin();
            for (auto it = s.begin(); it != s.end(); ++it) {
                if (set_c.find(*it) != set_c.end()) {
                    ++count;
                    maxLen = max(maxLen, count);
                    set_c.insert(*it);
                } else {
                    while (*ite != *it) {
                        set_c.erase(*ite);
                        ++ite;
                        --count;
                    }
                    ++ite;
                }
            }
            return maxLen;
        }

        int lengthOfLongestSubstring(string & s) {
            int m[256];
            memset(m, -1, sizeof(m));
            int maxLen = 0;
            int lastrepeat = -1;
            for (int i = 0; i < s.size(); ++i) {
                if (m[s[i]] != -1 && lastrepeat < m[s[i]]) {
                    lastrepeat = m[s[i]];
                } else {
                    maxLen = maxLen > i - lastrepeat ? maxLen : i - lastrepeat;
                }
                m[s[i]] = i;
            }
            return maxLen;
        }

};
