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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> temp;
        int path = 0;
        recursive(root, sum, ret, temp, path);
        return ret;
    }

    void recursive(TreeNode* root, int sum, vector<vector<int>> &ret, vector<int> &temp, int &path) {
        if (root == NULL) return;
        temp.push_back(root -> val);
        if (root ->left == NULL && root -> right == NULL && sum == (path+(root->val))) ret.push_back(temp);
        path += root -> val;
        recursive(root -> left, sum, ret, temp, path);
        recursive(root -> right, sum, ret, temp, path);
        path -= root -> val;
        temp.erase(temp.end()-1);
        return;
    }
};