package greedy;

public class canJumpLat {
    public boolean solution (int [] nums) {
        if (nums == null || nums.length == 0) return false;
        int n = nums.length, max = 0;
        for (int i = 0; i < n; ++i) {
            if (max >= n-1) return true;
            if (i > max) return false;
            max = Math.max(max, i+nums[i]);
        }
        return false; // 因为只需要判断是否能到达最后一个元素而不是跳过最后一个元素
    }
}