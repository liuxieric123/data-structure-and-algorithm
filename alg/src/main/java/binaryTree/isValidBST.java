package binaryTree;

public class isValidBST {
    private treeNode root;

    private static class treeNode {
        private int data;
        private treeNode right;
        private treeNode left;

        public treeNode (int val) {
            this.data = val;
        }
    }

    public treeNode max (treeNode root) {
        treeNode p = root;
        while (p.left != null) {
            p = p.left;
        }
        return p;
    }

    public treeNode min (treeNode root) {
        treeNode p = root;
        while (p.right != null) {
            p = p.right;
        }
        return p;
    }

    public boolean isValidBSTMaxMin (treeNode t) {
        boolean left;
        boolean right;
        // 终止条件，最后一个节点为null返回true
        if (t == null) return true;
        left = t.left == null || t.data > max(t.left).data;
        right = t.right == null || t.data < min(t.right).data;
        return left && right && isValidBSTMaxMin(t.left) && isValidBSTMaxMin(t.right);

    }

    public boolean isValidBSTBound (treeNode t, treeNode up, treeNode down) {
        if (t == null) return true;
        if (down != null && t.data <= down.data) return false;
        if (up != null && t.data >= up.data) return false;
        return isValidBSTBound(t.left, t, down) && isValidBSTBound(t.right, up, t);
    }
}