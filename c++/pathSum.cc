/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// T:O(n), S:O(n)
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        int global = 0;
        return dfs(root, sum, global);
    }

    bool dfs(TreeNode* root, int sum, int &global) {
        if (root == NULL) return false;
        global += root -> val;
        if (root -> left == NULL && root -> right == NULL){
            if (sum == global) return true;
        }
        bool ret = dfs(root -> left, sum, global) || dfs(root -> right, sum, global);
        global -= root -> val;
        return ret;
    }
};