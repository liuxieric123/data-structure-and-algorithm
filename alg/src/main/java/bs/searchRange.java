package bs;

class searchRange {
    public int[] solution(int[] nums, int target) {
        if (nums == null || nums.length == 0) return new int[]{-1,-1};
        int s = firstOne(nums, target);
        if (s == -1) return new int[]{-1, -1};
        int e = lastOne(nums, target);
        return new int []{s, e};
    }
    
    public int firstOne (int [] nums, int target) {
        int low = 0, high = nums.length - 1;
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] > target) high = mid - 1;
            else if (nums[mid] < target) low = mid + 1;
            else {
                if (mid == 0 || nums[mid-1] != target) return mid;
                else high = mid - 1;
            }
        }
        return -1;
    }
    
    public int lastOne (int [] nums, int target) {
        int low = 0, high = nums.length - 1;
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] < target) low = mid + 1;
            else if (nums[mid] > target) high = mid - 1;
            else {
                if (mid == nums.length - 1 || nums[mid + 1] > target) return mid;
                else low = mid + 1;
            }
        }
        return -1;
    }
}