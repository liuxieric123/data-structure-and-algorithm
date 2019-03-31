package divide;

class reversePairs {
    public int solution (int [] nums) {
        if (nums == null || nums.length <= 1) return 0;
        int n = nums.length;
        int s = 0;
        int sum = 0;
        mergeSort(nums, s, n-1, sum);
        return sum;
    }

    public void mergeSort(int [] nums, int s, int e, int sum) {
        if (s - e <= 0) return;
        int mid = (s + e) / 2 - 1;
        mergeSort(nums, s, mid, sum);
        mergeSort(nums, mid+1, e, sum);
        merge(nums,s, mid, e, sum);
    }

    public void merge(int [] nums, int s, int mid, int end, int sum) {
        int [] tmp = new int[end - s + 1];
        int index = 0;
        int p = s;
        int q = mid + 1;
        while (p <= mid && q <= end) {
            if (nums[p] <= nums[q]) {
                tmp[index++] = nums[p++];
            } else {
                sum += (mid-p+1);
                tmp[index++] = nums[q++];
            }
        }
        if (p >= mid) {
            while(q <= end) {
                tmp[index++] = nums[q++];
            }
        } else {
            while(p <= mid) {
                tmp[index+1] = nums[p+1];
            }
        }
        index = 0;
        for (int i = s; i <= end; ++i) {
            nums[i] = tmp[index++];
        }
    }
}