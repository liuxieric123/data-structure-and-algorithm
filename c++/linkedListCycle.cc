#include <unordered_set>

using std::unordered_set;

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
    bool hasCycle(ListNode * head) {
        unordered_set<ListNode *> node_set;
        while(head != nullptr) {
            if (node_set.find(head) != node_set.end()) return true;
            node_set.insert(head);
            head = head -> next;
        }
        return true;
    }

    bool hasCycle1(ListNode * head) {
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast) return true;
        }
        return false;
    }

    bool hasCycle2(ListNode * head) {
        ListNode dummy(0);
        ListNode * tmp;
        while(head != nullptr) {
            tmp = head;
            head = head -> next;
            if(tmp -> next == &dummy) return true;
            tmp -> next = &dummy;
        }
        return false;
    }
};