public class findMinRotate{
    public int solution(int[] nums) {
        int low = 0, high = nums.length - 1;
        while(low < high) {
            if (nums[low] < nums[high]) return nums[low];
            int mid = low + ((high - low) >> 1);
            if (nums[mid] > nums[high]) low = mid + 1;
            else high = mid;
        }
        return nums[low];
    }
}