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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == NULL) return ret;
        list<TreeNode *> vecTree;
        vecTree.push_back(root);
        while(vecTree.size() != 0) {
            int size = vecTree.size();
            vector<int> layer;
            for (int i = 0; i < size; ++i) {
                TreeNode * front = vecTree.front();
                layer.push_back(front -> val);
                if (front -> left != NULL) vecTree.push_back(front->left);
                if (front -> right != NULL) vecTree.push_back(front->right);
                vecTree.pop_front();
            }
            ret.push_back(layer);
        }
        return ret;
        
    }
};