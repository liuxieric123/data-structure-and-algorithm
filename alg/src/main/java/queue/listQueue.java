package queue;

public class listQueue {

    private Node head = null;
    private Node tail = null;
    private int length;
    private int capacity;

    private class Node {
        private int val;
        private Node next;

        public Node (int val) {
            this.val = val;
            this.next = null;
        }
    }

    public listQueue (int n) {
        this.length = 0;
        this.capacity = n;
    }

    public boolean enqueue (int val) {
        if (length == capacity) return false;
        if (head == null) {
            head = new Node(val);
            tail = head;
        } else {
            tail.next = new Node(val);
            tail = tail.next;
        }
        length++;
        return true;
    }

    public int dequeue () {
        if (head == tail) {
            if (head == null) {
                return false;
            } else {
                int tmp = head.val;
                head = null;
                tail = null;
                return tmp;
            }
        }
        int tmp = head.val;
        head = head.next;
        return tmp;
    }


}