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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        if (preorder.size() != inorder.size()) return NULL;
        map<int, int> index;
        for (int i = 0; i < inorder.size(); ++i) {
            index[inorder[i]] = i;
        }
        int start = 0;
        return dfs(preorder, inorder, start, 0, inorder.size()-1, index);
    }

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int &start, 
        int left, int right, map<int, int> & index) {
        if (left > right) return NULL;
        TreeNode * node = new TreeNode(preorder[start]);
        int idx = start;
        start += 1;
        if (left == right) return node;
        node -> left = dfs(preorder, inorder, start, left, index[preorder[idx]]-1, index);
        node -> right = dfs(preorder, inorder, start, index[preorder[idx]]+1, right, index);
        return node;
    }
};