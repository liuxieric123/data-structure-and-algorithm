package divide;

class importantReversePairs {
    public int solution(int[] nums) {
        if (nums == null || nums.length <= 1) return 0;
        int sum = mergeSort(nums, 0, nums.length-1);  
        return sum;
    }
    
    public int mergeSort(int[] nums, int s, int e) {
        if (s == e) return 0;
        int count = 0;
        int mid = s + (e - s) / 2;
        count += mergeSort(nums, s, mid);
        count += mergeSort(nums, mid+1, e);
        count += count(nums, s, mid, e);
        merge(nums, s, mid, e);
        return count;
        
    }
    
    public void merge(int[] nums, int s, int mid, int e) {
        int [] tmp = new int [e-s+1];
        int p = s;
        int q = mid+1;
        int index = 0;
        while(p <= mid && q <= e) {
            if (nums[p]<=nums[q]){
                tmp[index++] = nums[p++];
            } else {
                tmp[index++] = nums[q++];
            }
        }
        if (p > mid) {
            while(q <= e) {
                tmp[index++] = nums[q++];
            }
        } else {
            while(p <= mid) {
                tmp[index++] = nums[p++];
            }
        }
        index = 0;
        for (int i = s; i <= e; ++i) {
            nums[i] = tmp[index++];
        }
    }
    
    public int count(int [] nums, int s, int mid, int e) {
        if (s == e) return 0;
        int count = 0;
        int p = s;
        int q = mid + 1;
        while(p <= mid && q <= e) {
            if (nums[p] <= 2L*nums[q]) p++;
            else {
                count += (mid - p + 1);
                q++;
            }
        }
        return count;
    }
}