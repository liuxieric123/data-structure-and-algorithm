#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        ListNode * p = headA, * q = headB;
        while (p != q) {
            p = p != NULL ? p -> next : headB;
            q = q != NULL ? q -> next : headA;
        }
        return p;
    }

    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        ListNode * p = headA, * q = headB;
        int lenA = 0; int lenB = 0;
        while(p != NULL) {
            ++lenA;
            p = p -> next;
        }
        while(q != NULL) {
            ++lenB;
            q = q -> next;
        }
        if (lenA > lenB) for (int i = 0; i < lenA - lenB; ++i) headA = headA -> next;
        else for (int i = 0; i < lenB - lenA; ++i) headB = headB -> next;
        while (headA != headB) {
            headA = headA -> next;
            headB = headB -> next;
        }
        return headA;
    }
};