package stack;

public class stackWithArray {
    private int [] items;
    private int count;
    private int n;

    public stackWithArray(int n) {
        this.n = n;
        items = new int[n];
        this.count = 0;
    }

    public Boolean push (int val) {
        if (count >= n) return false;
        items[++count] = val;
        return true;
    }

    public int pop () {
        if (n == 0) return null;
        return items[count--];
    }
}