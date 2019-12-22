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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return NULL;
        return dfs(nums, 0, size - 1);
    }

    TreeNode* dfs(vector<int>& nums, int i, int j) {
        if (j < i) return NULL;
        if (i > j) return NULL;
        if (i == j) return new TreeNode(nums[i]);
        int mid = i + (j - i) / 2;
        TreeNode* cur = new TreeNode(nums[mid]);
        cur -> left = dfs(nums, i, mid - 1);
        cur -> right = dfs(nums, mid + 1, j);
        return cur;
    }
};