#include <queue>
#include <vector>
#include <algorithm>

using std::vector;
using std::greater;
using std::priority_queue;

class KthLargest {
public:

    KthLargest(int k, vector<int>& nums): n(k) {
        for (auto i : nums) {
            pq.push(i);
            if (pq.size() > n) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > n) pq.pop();
        return pq.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
};
