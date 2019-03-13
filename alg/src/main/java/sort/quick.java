package sort;

public class quick {
    private int [] data;
    public quick (int [] data) {
        this.data = data;
    }

    public void sort (int p, int q) {
        if (p >= q) return;
        int k = partition(p, q);
        sort(p, k-1);
        sort(k+1, q);

    }

    public int partition (int p, int q) {
        int tmp = data[q];
        int j = p;
        for (int i = p; i < q - 1; ++i) {
            if (data[i] <= tmp) {
                swap(data, j, i);
                j++;
            }
        }
        swap(data, j, q);
        return j;
    }

    public static void  swap(int [] a, int p, int q) {
        int tmp = a[p];
        a[p] = a[q];
        a[q] = tmp;
    }    
}