#include <vector>
#include <list>

using std::vector;
using std::list;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == NULL) return  ret;
        list<TreeNode *> liTree;
        liTree.push_back(root);
        while(liTree.size() != 0) {
            vector<int> layer;
            int size = liTree.size();
            for (int i = 0; i < size; ++i) {
                TreeNode * tmp = liTree.front();
                layer.push_back(tmp -> val);
                if (tmp -> left != NULL) liTree.push_back(tmp -> left);
                if (tmp -> right != NULL) liTree.push_back(tmp -> right);
                liTree.pop_front();
            }
            ret.push_back(layer);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    vector<vector<int>> levelOrderBottom1(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == NULL) return ret;
        levelOrderBottomRecursive(root, 0, ret);
        reverse(ret.begin(), ret.end());
        return ret;
    }

    void levelOrderBottomRecursive(TreeNode * root, int level, vector<vector<int>> & ret) {
        if (root == NULL) return;
        if (ret.size() <= level) ret.push_back({});
        ret[level].push_back(root -> val);
        if (root -> left != NULL) levelOrderBottomRecursive(root -> left, level + 1, ret);
        if (root -> right != NULL) levelOrderBottomRecursive(root -> right, level + 1, ret);
    }
};