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