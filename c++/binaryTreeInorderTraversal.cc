#include <stack>
#include <vector>

using std::stack;
using std::vector;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
    vector<int> inorderTraversalWithStack(TreeNode * root) {
        stack<TreeNode *> stTree;
        vector<int> ret;
        while(stTree.size() != 0 || root != NULL) {
            if (root != NULL) {
                stTree.push(root);
                root = root -> left;
            } else {
                if (stTree.size() > 0) {
                    root = stTree.top();
                    stTree.pop();
                    ret.push_back(root -> val);
                    root = root -> right;
                }
            }
        }
        return ret;
    }

    vector<int> inorderTraversal1(TreeNode * root) {
        vector<int> ret;
        inorderTraversalRecursive(ret, root);
        return ret;
    }

    void inorderTraversalRecursive(vector<int> & ret, TreeNode * root) {
        if (root == NULL) return;
        inorderTraversalRecursive(ret, root -> left);
        ret.push_back(root -> val);
        inorderTraversalRecursive(ret, root -> right);
    }
};