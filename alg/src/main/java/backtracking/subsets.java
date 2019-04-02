package backtracking;

import java.util.*;

public class subset {
    public List <List<Integer>> solution (int [] nums) {
        List <List<Integer>> result = new ArrayList <>();
        List <Integer> list = new ArrayList <>();
        rec(nums, result, list, 0);
        return result;
    }

    public void rec(int [] nums, List <List<Integer>> result, List <Integer> list, int count) {
        if (count == nums.length) {
            result.add(new ArrayList <>(list));
            return;
        } else {
            rec(nums, result, list, count+1);
            list.add(nums[count]);
            rec(nums, result, list, count+1);
        }
    }
}