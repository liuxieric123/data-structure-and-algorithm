
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        preorderRecursive(root, ret);
        return ret;
    }

    void preorderRecursive(TreeNode * root, vector<int> & ret) {
        if (root == NULL) return;
        ret.push_back(root -> val);
        preorderRecursive(root -> left, ret);
        preorderRecursive(root -> right, ret);

    }
};