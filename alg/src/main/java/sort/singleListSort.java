package sort;

public class singleListSort{
    private class ListNode {
        private int val;
        private ListNode next;

        public ListNode (int val) {
            this.val = val;
            this.next = null;
        }
    }

    public ListNode mergeSort (ListNode s) {
        if (s == null || s.next == null) return s;
        ListNode slow = s;
        ListNode fast = s.next;
        while(fast.next != null || fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode right = mergeSort(slow.next);
        slow.next = null;
        ListNode left = mergeSort(s);
        return merge(left, right);
    }

    public ListNode merge (ListNode left, ListNode right) {
        ListNode dummy = new ListNode(0);
        ListNode p = dummy;
        while(left != null && right != null ) {
            if (left.val > right.val) {
                p.next = right;
                right = right.next;
            } else {
                p.next = left;
                left = left.next;
            }
            p = p.next;
        }
        if (left != null) p.next = left;
        if (right != null) p.next = right;
        return dummy.next;
    }

    public void quickSort (ListNode s, ListNode end) {
        if (s == end || s == null || end == null) return;
        int pivot = s.val;
        ListNode i=s, j=s.next;
        while (j != end) {
            if (j.val <= pivot) {
                i = i.next;
                swap(i, j);
            }
            j = j.next;
        }
        swap(s, i);
        quickSort(s, i);
        quickSort(i.next, s);
    }

    public void swap(ListNode s, ListNode p) {
        int tmp = s.val;
        s.val = p.val;
        p.val = tmp;
    }
}