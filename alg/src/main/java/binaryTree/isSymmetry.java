package binaryTree;

import java.util.*;

public class isSymmetry {
    private class treeNode {
        private int val;
        private treeNode right;
        private treeNode left;

        public treeNode (int val) {
            this.val = val;
        }
    }
    public static boolean isSymm (treeNode root1, treeNode root2) {
        if (root1 == null && root2 == null) return true;
        if (root1 == null || root2 == null) return false;
        return root1.val == root2.val && isSymm(root1.right, root2.left) && isSymm(root1.left, root2.right);
    }

    public static boolean isSymmetry (treeNode p) {
        if (p == null) return true;
        return isSymm(p.right, p.left);
    }

    public static boolean isSymmetryWithStack (treeNode p) {
        if (p == null) return true;
        Stack<treeNode> stack = new Stack<>();

        stack.push(p.left);
        stack.push(p.right);
        while(!stack.isEmpty()) {
            treeNode node1 = stack.pop();
            treeNode node2 = stack.pop();
            if (node1 == null && node2 == null) continue;
            if (node1 == null || node2 == null) return false;
            if (node1.val != node2.val) return false;
            stack.push(node1.left);
            stack.push(node2.right);
            stack.push(node1.right);
            stack.push(node2.left);
        }
        return true;
    }
}