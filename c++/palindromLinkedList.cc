#include <stack>

using std::stack;

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
    public:
        bool isPalindromeStack(ListNode * head) {
            if (head == nullptr || head -> next == nullptr) return true;
            stack<ListNode *> sh;
            ListNode * tmp = head;
            while(tmp != nullptr) {
                sh.push(tmp);
                tmp = tmp -> next;
            }
            while (head != nullptr) {
                tmp = sh.top();
                sh.pop();
                if (head -> val != tmp -> val) return false;
                head = head -> next;
            }
            return true;
            
        }

        bool isPalindromReverse(ListNode * head) {
            if (head == nullptr || head -> next == nullptr) return true;
            int len = 0;
            ListNode * tmp = head;
            while (tmp != nullptr) {
                ++len;
                tmp = tmp -> next;
            }
            ListNode * q = nullptr;
            for (int i = 0; i < len / 2; ++i) {
                tmp = head;
                head = head -> next;
                tmp -> next = q;
                q = tmp;
            }
            if (len % 2 == 1) head = head -> next;
            for (int i = 0; i < len / 2; ++i) {
                if (q -> val != head -> val) return false;
                q = q -> next;
                head = head -> next;
            }
            return true;
        }

        ListNode * findMiddle(ListNode * head) {
            ListNode * fast = head;
            while (fast != nullptr && fast -> next != nullptr) {
                head = head -> next;
                fast = fast -> next -> next;
            }
            return head;
        }

        ListNode * reverse(ListNode * head) {
            ListNode * p = nullptr, * q = nullptr;
            while(head != nullptr) {
                p = head;
                head = head -> next;
                p -> next = q;
                q = p;
            }
            return q;
        }
        bool isPalindrome(ListNode * head) {
            if (head == nullptr || head -> next == nullptr) return true;
            ListNode * mid = findMiddle(head);
            ListNode * rev = reverse(mid);
            for (;head != mid; head = head -> next, rev = rev -> next) {
                if (head -> val != rev -> val) return false;
            }
            return true;
        }
};