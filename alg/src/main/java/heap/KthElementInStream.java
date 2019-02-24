package heap;

import java.util.*;

public class KthElementInStream {
    private Queue <Integer> minHeap = new PriorityQueue<>();
    private int k;
    public KthElementInStream (int [] nums, int k) {
        this.k = k;
        for (int num: nums) add(num);
    }

    public int add (int num) {
        if (k > minHeap.size()) {
            minHeap.add(num);
        } else {
            if (num > minHeap.peek()) {
                minHeap.poll();
                minHeap.add(num);
            }
        }
        return minHeap.peek();
    }
}