// https://leetcode.com/problems/clone-graph/submissions/

// Have to maintain a mapping from original to copy, can be done via DFS or BFS

class Solution {
public:
    unordered_map<Node*, Node*> copies;
    
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        
        if (copies.find(node) == copies.end()) {
            copies[node] = new Node(node -> val, {});
            for (auto &n : node->neighbors)
                (copies[node]->neighbors).push_back(cloneGraph(n));
        }
        return copies[node];
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/