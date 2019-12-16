
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k <=0) return head;
        int count = 1;
        ListNode * handle = head;
        while(handle -> next != NULL) {
            ++count;
            handle = handle -> next;
        }
        handle -> next = head;
        k = count - (k%count) - 1;
        for (int i = 0; i < k; ++i) head = head -> next;
        handle = head -> next;
        head -> next = NULL;
        return handle;
    }

    ListNode* rotateRight1(ListNode* head, int k) {
        if (head == NULL || k <=0) return head;
        int count = 1;
        ListNode * handle = head;
        while(handle -> next != NULL) {
            ++count;
            handle = handle -> next;
        }
        k %= count;
        ListNode * pre = head;
        ListNode * after = head;
        for (int i = 0; i < k; ++i) pre = pre -> next;
        while(pre != NULL && pre -> next != NULL) {
            pre = pre -> next;
            after = after -> next;
        }
        pre -> next = head;
        head = after -> next;
        after -> next = NULL;
        return head;
    }
};