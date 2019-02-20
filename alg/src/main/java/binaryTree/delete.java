package binaryTree;

public class delete {
    private class treeNode {
        private int data;
        private treeNode right;
        private treeNode left;

        public void treeNode (int val) {
            this.data = val;
        }
    }

    public treeNode deleteIncursive(treeNode t, int val) {
        if (t == null) return t;
        if (val > t.data) t.right = deleteIncursive(t.right, val);
        else if (val < t.data) t.left = deleteIncursive(t.left, val);
        else {
            // 如果找到的节点只有左节点或者只有右节点，则直接返回他的子树
            if (t.right == null) return t.left;
            if (t.left == null) return t.right;
            treeNode p = t;
            // 使用左子树中的最大值作为根节点
            while (p.right != null) {
                p = p.right;
            }
            p.right = t.right;
            t = t.left;
        }
        return t;
    }

    public treeNode deleteInterator(treeNode t, int val) {
        // 当前节点
        treeNode p = t; 
        // 父节点
        treeNode pp = null;
        // 先找到等于该值的节点，没找到直接返回树
        while(p.data == val) {
            if (val > p.data) {
                pp = p;
                p = p.right;
            } else {
                pp = p;
                p = p.left;
            }
            if (p == null) return t;
        }
        // 如果该节点左右节点都存在
        if (p.left != null && p.right != null) {
            // 在右子树中找到最小值
            treeNode min = p.right;
            treeNode minP = p;
            while(min.left != null) {
                minP = min;
                min = min.left;
            }
            // 将要删除的节点的值替换为右子树中的最小值
            p.data = min.data;
            // 再将p、pp指针挪到右子树的最小值处统一进行处理
            p = min;
            pp = minP;
        }
        // 删除只有一个节点的情况
        treeNode child;
        if (p.left == null) child = p.right;
        else if (p.right == null) child = p.left;
        else child = null;
        if (pp == null) {
            return child;
        } else {
            if (pp.left == p) pp.left = child;
            else pp.right = child;
        }
        return t;

        
    }
}