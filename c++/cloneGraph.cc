/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        Node * copy = new Node(node -> val, vector<Node*>(NULL));
        map_node.insert({node, copy});
        for (auto p : node -> neighbors) {
            if (map_node.find(p) != map_node.end()) copy -> neighbors.push_back(map_node[p]);
            else copy -> neighbors.push_back(cloneGraph(p));
        }
        return copy;
    }
private:
    unordered_map<Node*, Node*> map_node;
};