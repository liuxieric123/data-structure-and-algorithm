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
};