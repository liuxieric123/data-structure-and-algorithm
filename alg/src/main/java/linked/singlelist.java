package linked;

public class singlelist {

    private SNode head;
    
    public singlelist () {
        head = new SNode();
    }

    public void insertHead (int t) {
        SNode node = new SNode(t);
        head.next = node;
    }

    public void insertTail (int h) {
        SNode node = new SNode(h);
        SNode q = head;
        while (q.next != null) {
            q = q.next;
        }
        q.next = node;
    }

    public void deleteByIndex (int index) {


    }
    // 带头结点的单链表反转
    public SNode inverseWithHead (SNode head) {
        if (head == null || head.next == null || head.next.next == null) {
            return head;
        }
        SNode cur = head.next.next;
        head.next.next = null;
        while (cur != null) {
            SNode tmp = cur.next;
            cur.next = head.next;
            head.next = cur;
            cur = tmp;
        }
        return head;
    }
    // 不带头节点的单链表反转
    public SNode inverseWithoutHead (SNode h) {
        // 考虑如果节点是null的话，.next是什么
        SNode pre = null, cur = h, next = h.next;
        while( cur != null) {
            next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    // 单链表判断是否回文，使用单链表反转
    public Boolean isPalindrom (SNode s) {
        int len = 0;
        for (SNode cur = s;  cur != null; cur = cur.next, ++len);
        SNode pre = null, cur = s, next = s.next;
        for (int i = 0; i < len / 2; i++) {
            next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        if (len % 2 == 1) cur = cur.next;
        for (int i = 0; i < len / 2; i++) {
            if (pre.element != cur.element) {
                return false;
            }
            pre = pre.next;
            cur = cur.next;
        }
        return true;
    }

    // 找到单链表的中间节点
    public SNode findMiddle (SNode s) {
        SNode slow = s, fast = s.next;
        while (slow != null && fast != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    public static class SNode{

        private int element;

        private SNode next;

        public SNode(int element, SNode next) {
            this.element = element;
            this.next = next;
        }

        public SNode(int element) {
            this.element = element;
            this.next = null;
        }

        public SNode () {
            this.next = null;
        }

        public int getData() {
            return element;
        }
        
    }

}