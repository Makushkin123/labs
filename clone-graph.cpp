//https://leetcode.com/problems/clone-graph/
class Solution {
public:
    unordered_map<Node*,Node*> copied;
    
    Node* cloneGraph(Node* node) {
        if(copied.find(node)!=copied.end())return copied[node];
        Node* newnode;
        newnode=new Node(node->val, {});
        copied[node]=newnode;
        for(int i=0; i<node->neighbors.size(); i++)newnode->neighbors.push_back(cloneGraph(node->neighbors[i]));
        return newnode;
    }
};
