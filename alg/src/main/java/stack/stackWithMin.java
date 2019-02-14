package stack;
import java.util.Stack;

public class stackWithMin {
    public class stackWithMinUseStack {
        private Stack<Integer> s;
        private Stack<Integer> min;

        public void push(Integer val) {
            if (min.isEmpty() || val <= min.peek()) min.push(val);
            s.push(val);
        }

        public void pop() {
            if (s.peek() == min.peek()) min.pop();
            s.pop();
        }

        public Integer top() {
            return s.peek();
        }

        public Integer getMin() {
            return min.peek();
        }
    }

    public class stackWithMinUseList {
        private class Node {
            private Integer val;
            private Node next;

            Node (Integer val) {
                this.val = val;
                this.next = null;
            }
        }

        private Node head = null;
        private int min = Integer.MAX_VALUE;

        public void pop () {
            if (head == null) return;
            if (head.val == min) {
                min = head.next.val;
                head = head.next.next;
            } else {
                head = head.next;
            }
        }

        public void push (Integer val) {
            Node n = new Node(val);
            if (val <= min) {
                Node m = new Node(min);
                if (head == null) {
                    head = m;
                } else {
                    m.next = head;
                    head = m;
                }
            }
            n.next = head;
            head = n;
        }

        public Integer top () {
            return head.val;
        }

        public Integer getMin () {
            return min;
        }
    }
}