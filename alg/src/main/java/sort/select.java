package sort;

public class select {
    private int [] data;
    public select (int [] data) {
        this.data = data;
    }
    
    public void sort () {
        if (data.length <= 1) return;
        for (int i = 0; i < data.length - 1; ++i) {
            int pos = i;
            int j = i + 1;
            for (; j < data.length; ++j) {
                if (data[j] < data[pos]) {
                    pos = j;
                }
            }
            swap(data, i, pos);
        }
    }

    public static void swap(int [] data, int i, int j) {
        int tmp = data[j];
        data[j] = data[i];
        data[i] = tmp;
    }
}