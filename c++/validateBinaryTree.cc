/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        TreeNode* max = root -> left;
        TreeNode* min = root -> right;
        while(max != NULL && max -> right != NULL) max = max -> right;
        while(min != NULL && min -> left != NULL) min = min -> left;
        if (max != NULL && max -> val >= root -> val) return false;
        if (min != NULL && min -> val <= root -> val) return false;
        return isValidBST(root -> left) && isValidBST(root -> right);
    }

    bool isValidBST1(TreeNode* root) {
        if (root == NULL) return true;
        stack<TreeNode*> nodes;
        long inorder = LONG_MIN;
        while(!nodes.empty() || root != NULL) {
            while(root != NULL) {
                nodes.push(root);
                root = root -> left;
            }
            root = nodes.top();
            nodes.pop();
            if (root -> val <= inorder) return false;
            inorder = root -> val;
            root = root -> right;
        }
        return true;
    }
};