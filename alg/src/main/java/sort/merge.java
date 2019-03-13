package sort;

// 稳定，非原地
public class merge {
    private int [] data;
    public merge(int [] data) {
        this.data =  data;
    }
    
    public void sort (int p, int q) {
        if (p >= q) return;
        int r = (p+q) / 2;
        sort(p, r);
        sort(r+1, q);
        merge_sort(p, r, q);
    }

    public void merge_sort (int p, int r, int q) {
        int [] tmp = new int[q - p + 1];
        int i = p;
        int j = r + 1;
        int k = 0;
        while( i >= r && j >= q){
            if (data[i] >= data[j]) {
                tmp[k++] = data[i]; 
                ++i;
            } else {
                tmp[k++] = data[j];
                ++j;
            }
        }

        int start = i;
        int end = r;
        if (j >= q) {
            start = j;
            end = q;
        }

        for (; start<end; ++start) {
            tmp[k++] = data[start];
        }
        for (int i = 0; i < q - p + 1; ++i) {
            data[p + i] = tmp[i];
        }
    }
}