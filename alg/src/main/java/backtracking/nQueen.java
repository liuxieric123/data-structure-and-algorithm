package backtracking;

import java.util.*;

public class nQueen {

    public List<List<String>> solution(int n) {
        List <List<String>> set = new ArrayList<List <String>>();
        List <String> result = new ArrayList<>();
        boolean [] up = new boolean [n];
        boolean [] right = new boolean [2*n-1];
        boolean [] left = new boolean [2*n-1];
        cal(set, result, 0, n, up, right, left);
        return set;
    }

    public void cal(List <List<String>> set, List <String> result, 
                    int row, int n, boolean [] up, boolean [] right, 
                    boolean [] left) {
        if (row == n) {
            // 这个地方插入的是引用，应该使用result重新构建一个对象
            set.add(new ArrayList(result));
            return;
        } else {
            for (int i = 0; i < n; ++i) {
                if (up[i] || right[n+row-i-1] || left[i+row]) {
                    String s = "";
                    for (int j = 0; j < n; ++j) {
                        if (i != j) s += '.';
                        else s += 'Q';
                    }
                    result.add(s);
                    up[i] = true;
                    right[n+row-i-1] = true;
                    left[i+row] = true;
                    cal(set, result, row+1, n, up, right, left);
                    result.remove(result.size()-1);
                    up[i] = false;
                    right[n+row-i-1] = false;
                    left[i+row] = false;
                }
            }
        }
    }

    // public boolean isOk(List <String> result, int row, int idx, int n,
    //                     boolean [] up, boolean [] right, boolean [] left) {
    //     for (int i = 1; i < row+1; ++i) {
    //         int left = idx - i;
    //         int right = idx + i;
    //         if (left >= 0 && result.get(row - i).charAt(left) == 'Q') return false;
    //         if (right < n && result.get(row - i).charAt(right) == 'Q') return false;
    //         if (result.get(row - i).charAt(idx) == 'Q') return false;
    //     }
    //     return true;
    // }
    public List<List<String>> solveNQueens(int n) {
        List <List<String>> set = new ArrayList<List <String>>();
        List <String> result = new ArrayList<>();
        int up = 0, right = 0, left = 0;
        calBit(set, result, 0, n, up, right, left);
        return set;
    }
    
    public void calBit(List <List<String>> set, List <String> result, 
                    int row, int n, int up, int right, int left) {
        if (row == n) {
            set.add(new ArrayList(result));
            return;
        } else {
            int available = ((1 << n)-1) & (~(up | (right >> (n-row-1)) | (left >> row)));
            while(available != 0) {
                int p = available & -available;
                available ^= p;
                String s = "";
                for (int j = 0; j < n; ++j) {
                    if ((p >> j) != 1) s +='.';
                    else s += 'Q';
                }
                up ^= p;
                right ^= (p << (n-row-1));
                left ^= (p << row);
                result.add(s);
                calBit(set, result, row+1, n, up, right, left);
                up ^= p;
                right ^= (p << (n-row-1));
                left ^= (p << row);
                result.remove(result.size()-1);
            }
        }
    }
}