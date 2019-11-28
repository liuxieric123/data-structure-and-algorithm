struct TreeNode {
    TreeNode * left;
    TreeNode * right;
    int val;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution {
    bool sameTree(TreeNode * p, TreeNode * q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        return p -> val == q -> val &&
            sameTree(p->left, q->left) &&
            sameTree(p->right, q->right);
    }
};