package backtracking;

import java.util.*;

public class nQueen {

    public List<List<String>> solution(int n) {
        List <List<String>> set = new ArrayList<List <String>>();
        List <String> result = new ArrayList<>();
        cal(set, result, 0, n);
        return set;
    }

    public void cal(List <List<String>> set, List <String> result, 
                    int row, int n) {
        if (row == n) {
            // 这个地方插入的是引用，应该使用result重新构建一个对象
            set.add(new ArrayList(result));
            return;
        } else {
            for (int i = 0; i < n; ++i) {
                if (isOk(result, row, i, n)) {
                    String s = "";
                    for (int j = 0; j < n; ++j) {
                        if (i != j) s += '.';
                        else s += 'Q';
                    }
                    result.add(s);
                    cal(set, result, row+1, n);
                    result.remove(result.size()-1);
                }
            }
        }
    }

    public boolean isOk(List <String> result, int row, int idx, int n) {
        for (int i = 1; i < row+1; ++i) {
            int left = idx - i;
            int right = idx + i;
            if (left >= 0 && result.get(row - i).charAt(left) == 'Q') return false;
            if (right < n && result.get(row - i).charAt(right) == 'Q') return false;
            if (result.get(row - i).charAt(idx) == 'Q') return false;
        }
        return true;
    }

}