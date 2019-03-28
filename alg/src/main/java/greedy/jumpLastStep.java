package greedy;

class jumpLastStemp {
    public int solution (int [] nums) {
        if (nums == null || nums.length == 0) return 0;
        int n = nums.length, max = 0;
        int [] d = new int [n];
        for (int i = 0; i < n; ++i) {
            if (max >= n-1) return d[n-1];
            if (i > max) return -1;
            int last = Math.min(i+nums[i], n-1);
            for (int j = max+1; j <= last; ++j) {
                d[j] = d[i] + 1;
            }
            max = Math.max(i+nums[i], max);
        }
        return -1;
    }
}