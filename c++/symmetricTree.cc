#include <queue>

class TreeNode {
    TreeNode * left;
    TreeNode * right;
    int val;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
}

class Solution {
    bool isSymmetric1(TreeNode * root) {
        if (root == nullprt)  return true;
        std::queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()) {
            TreeNode * l = q.front();
            q.pop();
            TreeNode * r = q.front();
            q.pop();
            if (l == nullptr && r == nullptr) continue;
            if (l == nullptr || r == nullptr) return false;
            if (l -> val != r -> val) return false;
            q.push(l -> left);
            q.push(r -> right);
            q.push(l -> right);
            q.push(r -> left);
        }
        return true;
    }
    bool isSymmetric2(TreeNode * root) {
        if (root == nullptr) return true;
        return isSymmetricRecursive(root -> left, root -> right);
    }

    bool isSymmetricRecursve(TreeNode * left, TreeNode * right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr) return false;
        return (left -> val && right -> val) && isSymmetricRecursive(left -> left, right -> right)
            && isSymmetricRecursive(left -> right, right -> left);
    }
}