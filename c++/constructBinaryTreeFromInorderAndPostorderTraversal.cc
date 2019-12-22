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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) return NULL;
        if (inorder.size() == 0) return NULL;
        map<int, int> index;
        for (int i = 0; i < inorder.size(); ++i) {
            index.insert({inorder[i], i});
        }
        int start = postorder.size() - 1;
        return dfs(inorder, postorder, start, 0, start, index);

    }

    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int & start, 
        int left, int right, map<int, int> & index) {
        if (right < left) return NULL;
        TreeNode* node = new TreeNode(postorder[start]);
        int rootIdx = index[postorder[start]];
        start -= 1;
        if (right == left) return node;
        node -> right = dfs(inorder, postorder, start, index[postorder[rootIdx]]+1, right, index);
        node -> left = dfs(inorder, postorder, start, left, index[postorder[rootIdx]]-1, index);
        return node;
    }
};