package bs;

public class searchInsertPosition {
    public int solution (int [] nums, int val) {
        if (nums == null || nums.length == 0) return 0;
        int low = 0, high = nums.length - 1;
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] > val) high = mid - 1;
            else if (nums[mid] < val) low = mid + 1;
            else return mid;
        }

        return low;
    }
}