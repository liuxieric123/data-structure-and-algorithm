package binaryTree;

public class insert {
    private static class treeNode {
        private int data;
        private treeNode right;
        private treeNode left;

        public treeNode (int val) {
            this.data = val;
        }
    }

    public static void insert(treeNode t, int val) {
        treeNode p = t;
        if (p == null) {
            p = new treeNode(val);
            return;
        }
        while(true) {
            if (val > p.data) {
                if (p.right == null) {
                    p.right = new treeNode(val);
                    return;
                } 
                p = p.right;
            } else {
                if (p.left == null) {
                    p.left = new treeNode(val);
                    return;
                }
                p = p.left;
            }
        }
    }
}