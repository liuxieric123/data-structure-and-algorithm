package hashTable;

import java.util.*;

public class lru {
    private class Node {
        private int key;
        private int val;
        private Node pre;
        private Node next;

        public Node (int key, int val, Node pre, Node next) {
            this.key = key;
            this.val = val;
            this.pre = pre;
            this.next = next;
        }
    }

    private Node head = new Node (-1, -1, null, null); 
    private Map<Integer, Node> map = new HashMap <> ();

    public lru (int capacity) {
        Node cur = head;
        for (int i = 0; i < capacity -1; ++i) {
            cur.next = new Node (-1, -1, cur, null);
            cur = cur.next;
        }
        cur.next = head;
        head.pre = cur;
    }

    private void move2Head (Node cur) {
        if (cur == head) {
            head = head.pre;
            return;
        } else {
            cur.pre.next = cur.next;
            cur.next.pre = cur.pre;

            cur.pre = head;
            cur.next = head.next;
            head.next.pre = cur;
            head.next = cur;

        }
    }

    public void put (int key, int val) {
        if (map.containsKey(key)) {
            Node cur = map.get(key);
            cur.val = val;
            move2Head(cur);
        } else {
            head.key = key;
            head.val = val;
            map.put(key, head);
            head = head.pre;
        }
    }

    public int get (int key) {
        if (!map.containsKey(key)) {
            return -1;
        } else {
            Node cur = map.get(key);
            move2Head(cur);
            return cur.val;
        }
    }
}