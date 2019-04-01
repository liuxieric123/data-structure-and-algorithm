package backtracking;

import java.util.*;

class permutations {
    public List <List<Integer>> solution (int [] nums) {
        if (nums == null || nums.length == 0) return new ArrayList<>();
        List <List<Integer>> result = new ArrayList<>();
        List <Integer> list = new ArrayList<>();
        for (int num: nums) list.add(num);
        permutRec(list, 0, result);
        return result;
    }

    public void permutRec (List <Integer> nums, int start, List <List<Integer>> result) {
        if (start == nums.size()) {
            result.add(new ArrayList<>(nums));
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            Collections.swap(nums, i, start);
            permutRec(nums, start+1, result); // 不断交换新的数到start位，再往后的位继续递归调用
            Collections.swap(nums, i , start);
        }
    }
}