package bs;

public class bsearch {
    public int bsrecursive(int [] nums, int low, int high, int val) {
        if (low > high) return -1; //不取等于是为了判断low和high指向同一个数的时候的判断
        int mid = low + ((high - low) >> 1);
        if (nums[mid] == val) return mid;
        if (nums[mid] < val) {
            return bsrecursive(nums, mid + 1, high, val);
        } else {
            return bsrecursive(nums, low, mid - 1, val);
        }
    } 

    public int bs(int [] nums, int n, int val) {
        int low = 0;
        int high = n - 1;
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] == val && nums[mid - 1] < val) {
                return mid;
            } else if (nums[mid] < val) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    public int bsFirstEqual (int [] nums, int n, int val) {
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] > val) {
                high = mid - 1;
            } else if (nums[mid] < val) {
                low = mid - 1;
            } else {
                if (mid == 0 || nums[mid - 1] < val) return mid;
                else high = mid - 1;
            }
        }
        return -1;
    }
}