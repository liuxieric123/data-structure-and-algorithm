
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * handle1 = l1;
        ListNode * handle2 = l2;
        while(handle1 && handle2) {
            handle1 = handle1 -> next;
            handle2 = handle2 -> next;
        }
        bool carry = false;
        if (handle1 == NULL) handle1 = l2;
        else handle1 = l1;
        ListNode * ret = handle1;
        while(l1 != NULL && l2 != NULL) {
            int tmp = l1 -> val + l2 -> val;
            handle1 -> val = (tmp+carry) % 10;
            carry = (tmp+carry) > 9 ? true : false;
            l1 = l1 -> next;
            l2 = l2 -> next;
            if (handle1 -> next == NULL && carry){
                handle1 -> next = new ListNode(1);
                carry = false;
            }
            handle1 = handle1 -> next;
        }
        while (carry) {
            int tmp = handle1 -> val;
            handle1 -> val = (tmp+carry) % 10;
            carry = (tmp+carry) > 9 ? true : false;
            if (handle1 -> next == NULL && carry){
                handle1 -> next = new ListNode(1);
                carry = false;
            }
            handle1 = handle1 -> next;
        }
        return ret;
    }

    ListNode * addTwoNumbers1(ListNode * l1, ListNode * l2) {

    }
};