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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int ret = dfs(root, &maxSum);
        return ret > maxSum ? ret : maxSum;
    }

    int dfs(TreeNode* root, int *maxSum) {
        if (root -> left == NULL && root -> right == NULL) {
            *maxSum = max(*maxSum, root -> val);
            return root -> val;
        }
        int left = 0;
        int right = 0;
        if (root -> left != NULL){
            left = dfs(root -> left, maxSum);
        }
        if (root -> right != NULL) {
            right = dfs(root -> right, maxSum);
        }
        if (left < 0) left = 0;
        if (right < 0) right = 0;
        *maxSum = max(*maxSum, root->val + left + right);
        return max(root->val+left, root->val+right);
    }

    int maxPathSum1(TreeNode* root) {
        int maxSum = INT_MIN;
        int ret = dfs(root, maxSum);
        return ret > maxSum ? ret : maxSum;
    }

    int dfs1(TreeNode* root, int &maxSum) {
        if (root == NULL) return 0;
        int left = max(dfs(root -> left, maxSum), 0);
        int right = max(dfs(root -> right, maxSum), 0);
        maxSum = max(maxSum, root->val + left + right);
        return root->val + max(left, right);
    }
};