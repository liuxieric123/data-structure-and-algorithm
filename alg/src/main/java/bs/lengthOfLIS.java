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
}