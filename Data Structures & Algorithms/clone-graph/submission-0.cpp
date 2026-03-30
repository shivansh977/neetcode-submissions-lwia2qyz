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

class Solution {
private:
    unordered_map<Node*,Node*> mp;
public:
    Node* cloneGraph(Node* node) {
        if(mp.count(node)||node==nullptr) return mp[node];
        Node* clone=new Node(node->val);
        mp[node]=clone;
        clone->neighbors.resize(node->neighbors.size());
        for(int i=0;i<node->neighbors.size();i++){
            clone->neighbors[i]=cloneGraph(node->neighbors[i]);
        }
        return clone;
    }
};
