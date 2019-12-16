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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        unordered_set<ListNode *> set_pointer;
        while(head != NULL) {
            if (set_pointer.find(head) != set_pointer.end()) return head;
            else set_pointer.insert(head);
            head = head -> next;
        }
        return NULL;
    }
};