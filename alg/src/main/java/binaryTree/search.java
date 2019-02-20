package binaryTree;

public class search {
    private class treeNode {
        private int data;
        private treeNode right;
        private treeNode left;

        public treeNode (int val) {
            this.data = val;
        } 
    }

    public treeNode search (treeNode root, int val) {
        treeNode p = root;
        while (p != null) {
            if (val > p.data) p = p.right;
            if (val < p.data) p = p.left;
            if (val == p.data) break;
        }
        return p;
    }
}