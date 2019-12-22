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

    void flatten1(TreeNode* root) {
        vector<TreeNode*> ret;
        dfs(root, ret);
        ret.push_back(NULL);
        for (int i = 0; i < ret.size() - 1; ++i) {
            ret[i] -> right = ret[i+1];
            ret[i] -> left = NULL;
        }
    }

    void dfs(TreeNode* root, vector<TreeNode*> &vec) {
        if (root == NULL) return;
        vec.push_back(root);
        dfs(root->left, vec);
        dfs(root->right, vec);
    }
};