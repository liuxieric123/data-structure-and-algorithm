package heap;

import java.util.*;

class KthUglyNum {
    // 用最小堆实现
    public static int find(int n) {
        int uglyNum=0;
        Queue<Integer> minHeap = new PriorityQueue<>();
        minHeap.add(1);
        for (int i = 0; i < n; ++i) {
            uglyNum = minHeap.poll();
            if (2L * uglyNum <= Integer.MAX_VALUE) minHeap.add(2*uglyNum);
            if (3L * uglyNum <= Integer.MAX_VALUE) minHeap.add(3*uglyNum);
            if (5L * uglyNum <= Integer.MAX_VALUE) minHeap.add(5*uglyNum);
        }  
        return uglyNum;      
    }

    // 动态规划
    public static int findDP (int n) {
        if (n <= 0) return 0;
        int [] uglyNums = new int[n];
        uglyNums[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; ++i) {
            uglyNums[i] = min(2*uglyNums[p2], 3*uglyNums[p3], 5*uglyNums[p5]);
            if (uglyNums[i] == 2*uglyNums[p2]) ++p2;
            if (uglyNums[i] == 3*uglyNums[p3]) ++p3;
            if (uglyNums[i] == 5*uglyNums[p5]) ++p5;
        }
        return uglyNums[n-1];
    }

    public static int min(int a, int b, int c) {
        return Math.min(a, Math.min(b, c));
    }
}