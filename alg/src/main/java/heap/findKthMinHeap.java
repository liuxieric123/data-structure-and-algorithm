package heap;

import java.util.*;
import java.lang.*;

// time: O(n*log(k)) space: O(k)
public class findKthMinHeap {
    public static int find(int [] nums, int k ) {
        Queue <Integer> minHeap = new PriorityQueue<>();
        for (int num: nums) {
            if (minHeap.size() < k) {
                minHeap.add(num);
            } else {
                if (num > minHeap.peek()) {
                    minHeap.poll();
                    minHeap.add(num);
                } 
            }
        }
        return minHeap.peek();
    } 
}