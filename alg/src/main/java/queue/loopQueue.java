package queue;

public class loopQueue {
    private int [] data;
    private int head;
    private int tail;
    private int capacity;

    public loopQueue (int n) {
        this.capacity = n;
        data = new int [n];
        this.tail = 0;
        this.head = 0;
    }

    public int dequeue () {
        if (head == tail) return null;
        int tmp = data[head];
        head = (head + 1) % capacity;
        return tmp;
    }

    public boolean enqueue (int val) {
        if ((tail + 1) % capacity == head) return false;
        data[tail] = val;
        tail = (tail + 1) % capacity;
        return true;
    }
}