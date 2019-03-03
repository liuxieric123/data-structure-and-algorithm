package sort;


public class bubble {
    private int [] data;
    public bubble (int [] data) {
        this.data = data;
    }

    public void sort () {
        for (int i = 0; i < data.length; ++i) {
            for (int j = 0; j < data.length - i - 1; ++j) {
                if (data[j] > data[j+1]){
                    swap(data, j, j+1);
                }
            }
        }
        for (int i = 0; i < data.length; ++i) {
            System.out.print(data[i] + ' ');
        }
    }

    public static void swap(int [] data, int i, int j){
        int tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }
}