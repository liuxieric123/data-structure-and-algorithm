package sort;

public class sortColors {
    public void sortByCount (int [] nums) {
        if (nums == null || nums.length == 0) return;
        int [] count = new int [3];
        int index = 0;
        for (int i = 0; i < nums.length; ++i) {
            count[nums[i]]++;
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < count[i]; ++j) {
                nums[index] = i;
                index++;
            }

        }
    }

    public void sortByPoint (int [] nums) {
        if (nums == null || nums.length == 0) return;
        int i = 0, k = 0, j = nums.length - 1;
        while(k <= j) {
            if (nums[k] == 0) {
                swap(nums, i, k);
                i++;
                k++;
            } else if (nums[k] == 1) {
                k++;
            } else {
                swap(nums, k, j);
                j--;
            }
        }
    }

    public void swap(int [] data, int i, int j) {
        int tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }
}