public class lengthOfLIS {
    public int solution(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int n = nums.length;
        int [] d = new int [n];
        d[0] = 1;
        int max = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    d[i] = Math.max(d[j]+1, d[i]);
                    max = Math.max(max, d[i]);
                } else {
                    d[i] = Math.max(d[i], 1);
                }
            }
        }
        return max;
    }

    public int lengthOfLIS(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int [] d = new int [nums.length];
        int len = 0;
        for (int x: nums) {
            int i = insertPosition(d, len, x);
            d[i] = x;
            if (i == len) ++len;
        }
        return len;
    }
    
    public int insertPosition (int [] nums, int len, int d) {
        int low = 0, high = len - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] > d) high = mid - 1;
            else if (nums[mid] < d) low = mid + 1;
            else return mid;
        }
        return low;
    }
}