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

     Node* cloneGraph1(Node* node) {
        queue<Node*> qu_node;
        unordered_map<Node*, Node*> map_node;
        unordered_set<Node*> set_node;
        qu_node.push(node);
        while(!qu_node.empty()) {
            Node *cur = qu_node.front(); qu_node.pop();
            if (set_node.find(cur) != set_node.end()) continue;
            Node *copy;
            if(map_node.find(cur) == map_node.end()) {
                vector<Node*> tmp;
                copy = new Node(cur -> val, tmp);
                map_node.insert({cur, copy});
            } else {
                copy = map_node[cur];
            }
            for (auto p : cur -> neighbors) {
                Node *neighbor;
                if (map_node.find(p) == map_node.end()) {
                    vector<Node*> tmp;
                    neighbor = new Node(p -> val, tmp);
                    map_node.insert({p, neighbor});
                }
                else {
                    neighbor = map_node[p];
                }
                copy -> neighbors.push_back(neighbor);
                qu_node.push(p);
            }
            set_node.insert(cur);
        }
        return map_node[node];
    }
private:
    unordered_map<Node*, Node*> map_node;
};