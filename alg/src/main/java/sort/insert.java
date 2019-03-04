package sort;

public class insert {
    private int [] data;
    public insert (int [] data) {
        this.data = data;
    }

    public void sort () {
        for (int i = 1; i < data.length - 1; ++i){
            int val = data[i];
            int j = i - 1;
            for (; j >= 0; --j) {
                if (data[j+1] < data[j]){
                    data[j+1] = data[j];
                } else {
                    break;
                }
            }
            data[j] = val;
        }
    }
}