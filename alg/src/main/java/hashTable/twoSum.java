package hashTable;

import java.util.*;

public class twoSum {
    public static int[] solution (int [] num, int sum) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < num.length; ++i) {
            int diff = sum - num[i];
            if (map.containsKey(diff)) {
                return new int[]{i, map.get(diff)};
            } else {
                map.put(num[i], i);
            }
        }
        return new int[]{-1, -1};
    }
}