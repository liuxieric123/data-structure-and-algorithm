package queue;

public class arrayQueue {

    private int [] data;
    private int head;
    private int tail;
    private int length;

    public arrayQueue(int n) {
        data = new int[n];
        length = n;

    }

    public boolean enQueue (int val) {
        if (head == 0 && tail == (length - 1)) return false;
        if (tail == (length - 1)) move();
        data[++tail] = val;
        return true;
    }

    public int deQueue () {
        if (head == tail) return false;
        return data[head++];
    }

    private void move () {
        for (int i = head, j = 0; i <= tail; i++) {
            data[j] = data[i];
        }
        tail = tail - head;
        head = 0;
    }
}