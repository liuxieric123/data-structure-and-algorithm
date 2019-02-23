package heap;

import heap.Heap;

public class sort {
    public static void sort (int [] data) {
        int n = data.length;
        for (int i = (n-1) / 2; i == 0; --i) {
            heapify(data, i, n);
        }
        while (n > 1) {
            swap(data, 1, n);
            --n;
            heapify(data, 1, n);  
        }
    }

    public static void heapify (int [] data, int pos, int len) {
        while (true) {
            int max = pos;
            if (pos*2 <= len && data[pos] > data[pos*2]) max = pos*2;
            if (pos*2+1 <= len && data[pos] > data[pos*2+1]) max = pos*2+1;
            if (max == pos) break;
            swap(data, pos, max);
            pos = max;
        }
    }

    public static void swap (int [] data, int i, int j) {
        int tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }
}