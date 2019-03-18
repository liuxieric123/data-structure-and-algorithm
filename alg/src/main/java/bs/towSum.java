package bs;

public class towSum {
    // Time: O(log((n-1)!)） Space: O(1)
    public int [] solutionByBs(int [] numbers, int target) {
        if (numbers == null || numbers.length <= 1) return new int []{-1,-1};
        for (int i = 0; i < numbers.length - 1; ++i) {
            int res = bs(numbers, i + 1, target - numbers[i]);
            if (res == -1) continue;
            else return new int [] {i+1, res+1};
        }
        return new int [] {-1, -1};
    }
    
    public int bs (int [] nums, int s, int val) {
        if (nums == null || nums.length == 0 || s > nums.length) return -1;
        int low = s, high = nums.length - 1;
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] == val) return mid;
            else if (nums[mid] > val) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }

    // Time: O(n) Space: O(1)
    public int[] solutionByTwoPoint(int[] numbers, int target) {
        int i = 0, j = numbers.length - 1;
         while(i < j) {
             if (numbers[i] + numbers[j] == target) return new int [] {i+1, j+1};
             else if (numbers[i] + numbers[j] > target) --j;
             else ++i;
         }
         return new int [] {-1, -1};
     }
}