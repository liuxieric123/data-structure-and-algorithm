/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;
        queue<Node*> qu_node;
        qu_node.push(root);
        int count = 1;
        while(!qu_node.empty()) {
            int index = 1;
            Node* cur = qu_node.front();
            qu_node.pop();
            if (cur->left) qu_node.push(cur->left);
            if (cur->right) qu_node.push(cur->right);
            while(!qu_node.empty() && index < count) {
                Node* next = qu_node.front();
                qu_node.pop();
                if (next->left) qu_node.push(next->left);
                if (next->right) qu_node.push(next->right);
                cur -> next = next;
                cur = next;
                ++index;
            }
            count *= 2;
        }
        return root;
    }

    Node* connect(Node* root) {
        if (root == NULL || root -> left == NULL) return root;
        if (root -> right) root -> left -> next = root -> right;
        if (root -> next) root -> right -> next = root -> next -> left;
        connect(root -> left);
        connect(root -> right);
        return root;
    }

    
};