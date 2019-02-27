package graph;

import java.util.*;

public class firstSearch {

    public class Graph {
        public int v;
        public LinkedList<Integer> adj[];
        private boolean foundDFS = false;

        public Graph (int v) {
            this.v = v;
            adj = new LinkedList[v];
            for (int i = 0; i < v; ++i) {
                adj[i] = new LinkedList<Integer> ();
            }
        }

        public void addEdge(int s, int t) {
            adj[s].add(t);
            adj[t].add(s);
        }
    

        public void BFS (int s, int t) {
            Queue <Integer> queue = new LinkedList<> ();
            int [] prev = new int[v];
            boolean [] visited = new boolean [v];
            for (int i = 0; i < v; ++i) {
                prev[i] = -1;
                visited[i] = false;
            }
            queue.add(s);
            visited[s] = true;
            while (queue.size() != 0) {
                int cur = queue.poll();
                for (int i = 0; i < adj[cur].size(); ++i) {
                    int q = adj[cur].get(i);
                    if (!visited[q]) {
                        if (q == t) {
                            print(prev, s, t);
                            return;
                        }
                        queue.add(q);
                        visited[q] = true;
                        prev[q] = cur;
                    }
                }
            }
        }

        public void DFS (int s, int t) {
            boolean [] visited = new boolean [v];
            int [] prev = new int [v];
            for (int i = 0; i < v; ++i) {
                prev[i] = -1;
                visited[i] = false;
            }
            visited[s] = true;
            recurDFS(s, t, visited, prev);
            print(prev, s, t);
            foundDFS = false;
        }

        private void recurDFS (int s, int t, boolean [] visited, int [] prev) {
            visited[s] = true;
            if (s == t) {
                foundDFS = true;
                return;
            }
            for (int i = 0; i < adj[s].size(); ++i) {
                if (foundDFS) return;
                int q = adj[s].get(i);
                if (!visited[q]) {
                    prev[q] = s;
                    recurDFS(q, t, visited, prev);
                }
            }
        }

        public void print(int [] prev, int t, int s) {
            // 这个实现是倒序的
            // int cur = prev[s];
            // System.out.print(s);
            // while(cur != t) {
            //     System.out.print(cur);
            //     cur = prev[cur];
            // }
            // System.out.print(t);

            //使用递归实现正序
            if (s == t || prev[t] == -1) {
                System.out.print(s);
                return;
            } else {
                print(prev, t, prev[s]);
                System.out.print(s);
            }
        }
    }
}