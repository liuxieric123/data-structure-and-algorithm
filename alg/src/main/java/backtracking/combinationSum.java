package backtracking;

import java.util.*;

public class combinationSum {
    public List <List<Integer>> solution (int [] candidates, int target) {
        List <List<Integer>> result = new ArrayList <>();
        List <Integer> list = new ArrayList <>();
        combinate(candidates, 0, 0, result, list, target);
        return result;
    }

    public void combinate (int [] candidates, int start, int sum, List <List<Integer>> result, List <Integer> list, int target) {
        if (sum == target) {
            result.add(new ArrayList <>(list));
            return;
        } else {
            // 从start开始避免重复的结果数组
            for (int i = start; i < candidates.length; ++i) {
                if (sum + candidates[i] <= target) {
                    sum += candidates[i];
                    list.add(candidates[i]);
                    combinate(candidates, i, sum, result, list, target);
                    sum -= candidates[i];
                    list.remove(list.size()-1);
                }
            }
        }
    }
}