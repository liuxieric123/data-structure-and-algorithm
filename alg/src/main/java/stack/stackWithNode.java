package stack;

public class stackWithNode {

    private Node head = null;
    
    public int pop () {
        if (head == null) {
            return -1;
        }
        int val = head.val;
        head = head.next;
        return val;
    }

    public void push (int val) {
        Node n = new Node(val);
        if (head == null) {
            head = n;
        } else {
            n.next = head;
            head = n;
        }
    }

    public void printAll () {
        Node n = head;
        while(n != null) {
            System.out.println(n.val);
            n = n.next;
        }  
    }

    private static class Node {
        private int val;
        private Node next;
        
        public Node (int val) {
            this.val = val;
            this.next = null;
        }
    }
}