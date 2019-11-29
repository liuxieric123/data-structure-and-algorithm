struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
    ListNode * reverseLinkedList(ListNode * head) {
    }

    ListNode * reverseLinkedListIterative(ListNode * head) {
        ListNode * p = nullptr, * q = nullptr;
        while(head) {
            p = head -> next;
            head -> next = q;
            q = head;
            head = p;
        }
        return q;
    }

    ListNode * reverseLinkedListRecursive(ListNode * head) {
        if (head == nullptr || head -> next == nullptr) return head;
        ListNode * h = reverseLinkedListRecursive(head->next);
        // 将自身挪到返回的节点后面，然后给自己的下一个节点弄成null
        head -> next -> next = head;
        head -> next = nullptr;
    }
};