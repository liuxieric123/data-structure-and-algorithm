package heap;

public class Heap {
    private int [] data; // 用于存放堆数据的数组
    private int count; // 现在的堆有多少个数据
    private int n; // 堆的容量

    public Heap (int capacity) {
        this.data = new int [capacity + 1];
        this.n = capacity;
        this.count = 0;
    }

    public void insert (int val) {
        if (count >= n) return;
        data[++count] = val;
        int i = count;
        while(i > 1 && data[i] > data[i/2] ) {
            swap(data, i, i / 2);
            i = i / 2;
        } 
    }

    private static void swap (int [] data, int n1, int n2) {
        int tmp = data[n1];
        data[n1] = data[n2];
        data[n2] = tmp; 
    }

    public void deleteMax () {
        swap(data, 1, count);
        --count;
        int i = 1;
        while (true) {
            int pos = i;
            if (data[i] < data[i*2] && data[i] < data[i*2+1]) {
                pos = i*2;
            }else if (data[i] < data[i*2]) {
                pos = i * 2;
            }else if (data[i] < data[i*2+1]) {
                pos = i * 2 + 1;
            }else {
                break;
            }
            if (i == pos) break;
            swap(data, i, pos); 
            i = pos;      
        }
    }
}