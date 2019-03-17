package bs;

public class searchInRotatedSortedArray {
    public int solution (int [] nums, int target) {
        if (nums == null || nums.length == 0) return -1;
        int low = 0, high = nums.length - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[low]) { // 先判断在哪半边有序序列
                if (target < nums[mid] && target >= nums[low]) high = mid - 1;
                else low = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }
        }
        return -1;
    }
}