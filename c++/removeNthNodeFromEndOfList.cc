/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy;
        for (int i = 0; i < n; ++i) {
            pre = pre -> next;
            if (pre == NULL) return NULL;
        }
        ListNode *after = &dummy;
        while(pre -> next != NULL) {
            pre = pre -> next;
            after = after -> next;
        }
        after -> next = after -> next -> next;
        return dummy.next;
    }
};