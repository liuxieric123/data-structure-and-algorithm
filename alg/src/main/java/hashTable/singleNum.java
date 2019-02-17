package hashTable;

import java.util.*;

public class singleNum {
    public int solutionWithSet (int [] nums) {
        Set<Integer> set = new HashSet<>();
        int sum = 0;
        int setSum = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (!set.contains(nums[i])) {
                set.add(nums[i]);
                sum += nums[i];
                setSum += nums[i];
            } else {
                sum += nums[i];
            }

        }
        return 2 * setSum - sum;
    }

    public int solutionWithXOR (int [] nums) {
        int result = 0;
        for (int i = 0; i < nums.length; ++i) {
            result = result ^ nums[i];
        }

        return result;
    }
}