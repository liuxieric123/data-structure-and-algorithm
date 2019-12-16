
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
        k %= count;
        for (int i = 0; i < count - k - 1; ++i) head = head -> next;
        handle = head -> next;
        head -> next = NULL;
        return handle;
    }
};