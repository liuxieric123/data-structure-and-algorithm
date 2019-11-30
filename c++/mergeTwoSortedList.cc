struct ListNode {
    ListNode * next;
    int val;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
        ListNode * result = new ListNode(0);
        ListNode * tmp = result;
        while (l1 != nullptr && l2 != nullptr) {
            if(l1 -> val <= l2 -> val) {
                tmp -> next = l1;
                l1 = l1 -> next;
                tmp = tmp -> next;
            } else {
                tmp -> next = l2;
                l2 = l2 -> next;
                tmp = tmp -> next;
            }
        }
        l1 = l1 == nullptr ? l2 : l1;
        tmp -> next = l1;
        return result -> next;
    }
};