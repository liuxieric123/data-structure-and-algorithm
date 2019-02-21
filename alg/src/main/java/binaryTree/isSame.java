package binaryTree;

import java.util.*;

public class isSame {
    private class treeNode {
        private int val;
        private treeNode right;
        private treeNode left;

        public treeNode (int val) {
            this.val = val;
        }
    }

    public static boolean isSame(treeNode root1, treeNode root2) {
        if (root1 == null && root2 == null) return true;
        if (root1 == null || root2 == null || root1.val != root2.val ) return false;
        return isSame(root1.left, root2.left) && isSame(root1.right, root2.right);
    }

    public static boolean isSameInterative(treeNode root1, treeNode root2) {
        Stack<treeNode> stack = new Stack<> ();
        stack.push(root1);
        stack.push(root2);
        while(!stack.isEmpty()) {
            treeNode p1 = stack.pop();
            treeNode p2 = stack.pop();
            // 在树中经常要进行这样的判断防止NPE
            if (p1 == null && p2 == null) continue;
            if (p1 == null || p2 == null) return false;
            if (p1.val != p2.val) return false;
            stack.push(p1.left);
            stack.push(p2.left);
            stack.push(p1.right);
            stack.push(p2.right);
        }
        return true;
    }

}