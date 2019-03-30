package divide;

public class maximumSubarray{
    public int solution (int [] nums) {
        int max = Integer.MIN_VALUE;
        int cur = 0;
        for(int i = 0; i < nums.length; ++i) {
            cur = cur <= 0 ? nums[i] : (cur+nums[i]);
        }
        return max;
    }
}