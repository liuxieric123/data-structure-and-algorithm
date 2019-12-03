#include <algorithm>
#include <climits>

using std::min;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return minDepthRecursive(root, 1, INT_MAX);
    }

    int minDepthRecursive(TreeNode * root, int now, int minD) {
        if (root -> left == NULL && root -> right == NULL) return min(minD, now);
        ++now;
        if (root -> left != NULL) minD = min(minDepthRecursive(root -> left, now, minD), minD);
        if (root -> right != NULL) minD = min(minDepthRecursive(root -> right, now ,minD), minD);
        return minD;
    }

    int minDepth1(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        if (root->left == NULL) return minDepth(root->right) + 1;
        if (root->right == NULL) return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};