package binaryTree;

import java.util.*;
import java.lang.*;

public class traversing {
    private class treeNode {
        private int val;
        private treeNode left;
        private treeNode right;

        public treeNode (int val) {
            this.val = val;
        }
    }

    public static void preorder (treeNode root, List<Integer> result) {
        if (root == null) return;
        result.add(root.val);
        preorder(root.left, result);
        preorder(root.right, result);
    }

    public static void inorder (treeNode root, List<Integer> result) {
        if (root == null) return;
        inorder(root.left, result);
        result.add(root.val);
        inorder(root.right, result);

    }

    public static void postorder (treeNode root, List<Integer> result) {
        if (root == null) return;
        postorder(root.left, result);
        postorder(root.right, result);
        result.add(root.val);
    }
}