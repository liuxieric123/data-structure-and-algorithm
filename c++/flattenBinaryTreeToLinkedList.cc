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
    void flatten(TreeNode* root) {
        TreeNode * pointer = NULL;
        dfs(root, pointer);
        return;
    }

    void dfs(TreeNode*root, TreeNode * &pointer) {
        if (root == NULL) {
            return;
        }
        dfs(root -> right, pointer);
        dfs(root -> left, pointer);
        root -> right = pointer;
        root -> left = NULL;
        pointer = root;
    }
};