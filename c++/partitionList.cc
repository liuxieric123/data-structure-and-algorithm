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
    ListNode* partition(ListNode* head, int x) {
        ListNode small(0);
        ListNode greater(0);
        ListNode *s = &small;
        ListNode *g = &greater;
        while(head != NULL) {
            if (head -> val < x) {
                s -> next = head;
                s = s -> next;
            } else {
                g -> next = head;
                g = g -> next;
            }
            head = head -> next;
        }
        s -> next = greater.next;
        g -> next = NULL;
        return small.next;

    }
};