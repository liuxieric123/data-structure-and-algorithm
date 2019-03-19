package bs;

public class  singleNonDuplicate{
    public int solution(int[] nums) {
            int low = 0, high = nums.length - 1;
            while (low <= high) {
                int mid = low + ((high - low) >> 1);
                if (mid - 1 >=0 && nums[mid] == nums[mid - 1]) --mid;
                else if (mid+1 < nums.length && nums[mid] == nums[mid+1]) {}
                else return nums[mid];
                if ((mid - low) % 2 == 0) low = mid + 2;
                else high = mid - 1;
            }
            return -1;
    }
}