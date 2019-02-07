package linked;

public class singlelist {

    private SNode head = null;

    public void insertHead (int t) {
        SNode node = new SNode(t);
        if (head == null) {
            head = node;
        } else {
            node.next = head;
            head.next = node;
        }
    }

    public void insertTail (int h) {
        SNode node = new SNode(h);
        SNode q = head;
        while (q != null && q.next != null) {
            q = q.next;
        }
        q.next = node;
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

        public int getData() {
            return element;
        }
        
    }

}