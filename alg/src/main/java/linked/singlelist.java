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
    // 判断单链表中是否存在环
    public Boolean isLoop (SNode s) {
        SNode slow = s, fast = s.next;
        while (fast != null) {
            if (fast == slow) return true;
            slow = slow.next;
            fast = fast.next.next;
        }
        return false;
    }

    // 合并两个有序单链表
    public SNode mergeTwoSortedSinglelist (SNode s1, SNode s2) {
        SNode dummy = new SNode(), p = dummy;
        while(s1 != null && s2 != null) {
            if (s1.element < s2.element) {
                p.next = s1;
                s1 = s1.next;
            } else {
                p.next = s2;
                s2 = s2.next;
            }
            p = p.next;
        }
        if (s1 != null) p.next = s1;
        if (s2 != null) p.next = s2;
        return dummy.next;
    }

    // 移除单链表的倒数第n个节点
    public SNode removeNthFromEnd (SNode s, int n) {
        SNode dummy = new SNode(); 
        dummy.next = s;
        SNode p = dummy, q = dummy;
        int i;
        for (i = 0; p != null && i < n; i++) p = p.next;
        if (i < n) return dummy.next;
        while(p != null) {
            p = p.next;
            q = q.next;
        }
        q.next = q.next.next;
        return dummy.next;
    }

    // 单链表实现lru
    public class lru{

        SNode data = new SNode();

        private final static int DEFAULT_CAPACITY = 10;

        public int length = 0;

        public void put (int val) {
            SNode pre = findByValueReturnPre(val);
            if (pre != null) {
                data.next = pre.next;
                pre.next = pre.next.next;
            } else {
                if (length >= DEFAULT_CAPACITY)  deleteEnd();  
                SNode tmp = new SNode(val);
                tmp.next = data.next;
                data.next = tmp; 
            }
        }

        private SNode findByValueReturnPre (int val) {
            SNode p = data;
            SNode pre = null;
            while (p != null) {
                if (p.element == val) return pre;
                pre = p;
                p = p.next;
            }
            return null;
        }

        private void deleteEnd () {
            SNode head = data;
            while(head.next.next != null) {
                head = head.next;
            }
            head.next = null;
        }
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