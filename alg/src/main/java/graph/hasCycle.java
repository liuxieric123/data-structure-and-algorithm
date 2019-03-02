package graph;

import java.util.*;

public class hasCycle {

    private class graphNode {
        private List<List<Integer>> data;

        public graphNode (int n) {
            data = new ArrayList<> (n);
            for (int i = 0; i < n; ++i) {
                data.add(new LinkedList<>());
            }
        }

        public void add (int n1, int n2) {
            data.get(n1).add(n2);
        }
    }

    public boolean hasCycle(graphNode s, boolean [] onStack, boolean [] checked, int index, Stack <Integer> s){
        if (onStack[index]) return true;
        onStack[index] = true;
        for (int i = 0; i < s.data.get(index).size(); ++i) {
            if (!checked[s.data.get(index).get(i)] && hasCycle(s, onStack, checked, s.data.get(index).get(i))) {
                return true;
            }
        }
        checked[index] = true;
        s.push(index);
        onStack[index] = false;
        return true;
    }

    public boolean isOK (int n, int [][] paris) {
        if (n <= 0 && paris == null && paris.length == 0) return true;
        graphNode graph = new graphNode(n);
        for (int i = 0; i < paris.length; ++i) {
            graph.add(paris[i][1], paris[i][0]);
        }
        boolean [] onStack = new boolean[n];
        boolean [] checked = new boolean[n];
        Stack <Integer> s = new Stack<>();
        for (int i = 0; i < n; ++i)
            if (!checked[i] && hasCycle(graph, onStack, checked, i, s))
                return false;
        for (int i = 0; i < n; ++i) {
            System.out.print(s.pop());
        }
        return true;
    }

    public boolean topoSorted(graphNode s, int [] inDegree, Queue <Integer> zero, int n, Queue<Integer> q) {
        if (n <= 0) return true;
        int count = 0;
        while (!zero.isEmpty()) {
            int index = zero.poll();
            q.add(index);
            for (int i = 0; i < s.data.get(index).size(); ++i) {
                if (--inDegree[s.data.get(index).get(i)] == 0) 
                    zero.add(s.data.get(index).get(i));
            }
            count++;
        }
        return count == n;
    }

    public boolean isOKTopoSorted (int [][] pairs, int n) {
        if (n <= 0 && pairs == null && pairs.length == 0) return true;
        graphNode s = new graphNode(n);
        int [] inDegree = new int [n];
        Queue<Integer> zero = new LinkedList<>();
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; ++i) {
            s.add(pairs[i][1], pairs[i][0]);
            inDegree[pairs[i][0]]++;
        }
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) 
                zero.add(i);
        }
        boolean flag = topoSorted(s, inDegree, zero, n, q);
        if (flag) {
            for (int i = 0; i < n; i++){
                System.out.print(q.poll());
            }
        } 

        return flag;
        
    }
}