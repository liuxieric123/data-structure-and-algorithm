package sort;

import java.util.*;

public class longestConsecutiveSequence {
    public int solutionBySet (int [] nums) {
        if (nums == null || nums.length == 0) return 0;
        Set <Integer> set = new HashSet<>();
        for (int i = 0; i < nums.length; ++i) set.add(nums[i]);
        int max = 1;
        for (int i = 0; i < nums.length && !set.isEmpty(); ++i) {
            int low = nums[i], high = nums[i] + 1;
            while(set.contains(low)) set.remove(low--);
            while(set.contains(high)) set.remove(high++);
            max = Math.max(max, high - low -1);
        }
        return max;
    }

    public int solutionBySort (int [] nums) {
        if (nums == null || nums.length == 0) return 0;
        Arrays.sort(nums);
        int p = 0, len = 1, max = 0;
        while(p < nums.length) {
            while(p < nums.length - 1) {
                if (nums[p+1] > nums[p] + 1) break;
                if (nums[p+1] == nums[p] + 1) ++len;
                ++p;
            }
            max = Math.max(max, len);
            len = 1;
            ++p;
        }
        return max;
    }
}