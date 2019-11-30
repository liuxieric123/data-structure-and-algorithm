#include <forward_list>
#include <climits>

using std::forward_list;

class minStack {
    private:
        forward_list<int> stack;
        int min;
    public: 
        minStack(): min(INT_MAX) {
            stack.insert_after(stack.before_begin(), INT_MAX);
        }
        void push(int x) {
            if (x <= min) {
                stack.insert_after(stack.before_begin(), min);
                min = x;
            }
            stack.insert_after(stack.before_begin(), x);
        }
        int pop() {
            if (stack.front() == min) {
                stack.erase_after(stack.before_begin());
                min = stack.front();
            }
            stack.erase_after(stack.before_begin());
        }
        int top() {
            return stack.front();
        }
        int getMin() {
            return min;
        }
};