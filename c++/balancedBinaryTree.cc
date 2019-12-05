#include <cstdio>
#include <algorithm>

using std::abs;
using std::max;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        int left = depth(root -> left, 0);
        int right = depth(root -> right, 0);
        if (abs(left - right)>1) return false;
        return isBalanced(root -> left) && isBalanced(root ->right);
    }
    int depth(TreeNode * root, int level) {
        if (root == NULL) return level;
        int right =  depth(root -> right, level + 1);
        int left = depth(root -> left, level + 1);
        return max(right, left);
    }

    bool isBalanced1(TreeNode* root) {
        if (root == NULL) return true;
        return depth1(root, 0) != -1;
    }
    int depth1(TreeNode * root, int level) {
        if (root == NULL) return level;
        int right =  depth(root -> right, level + 1);
        if (right == -1) return -1;
        int left = depth(root -> left, level + 1);
        if (left == -1) return -1;
        if (abs(left - right) > 1) return -1;
        return max(right, left);
    }
};