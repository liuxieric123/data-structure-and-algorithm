#include <forward_list>
#include <climits>

using std::forward_list;

class minStack {
    private:
        forward_list<int> stack;
        int min;
    public: 
        minStack(): min()
};