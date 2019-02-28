package graph;

import java.util.*;

public class cloneGraph {
    // 这里说的是简单图，只要是图所有顶点都是存在联系的，也就是通过一个顶点是可以遍历所有顶点的
    private class undirectedGraph{
        private int x;
        private List<undirectedGraph> neighbour;

        public undirectedGraph(int val) {
            this.x = val;
            this.neighbour = new LinkedList<>();
        }
    }

    private Map<undirectedGraph, undirectedGraph> map = new HashMap<>();
    public undirectedGraph clone(undirectedGraph s) {
        if (s == null) return null;
        undirectedGraph copy = new undirectedGraph(s.x);
        map.put(s, copy);
        for (int i = 0; i < s.neighbour.size(); ++i) {
            if (map.containsKey(s.neighbour.get(i))) copy.neighbour.add(map.get(s));
            else copy.neighbour.add(s.neighbour.get(i));
        }
        return copy;
    }
}