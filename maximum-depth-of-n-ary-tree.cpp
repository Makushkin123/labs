https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
   int maxDepth(Node* root) {
queue<pair<Node*,int>> q;
if(root) q.push({root,1});
int depth=0;
while(!q.empty()){
pair<Node*,int> point = q.front();
q.pop();
depth = point.second;
for(auto& i : point.first->children){
q.push({i,point.second+1});
}
}
return depth;
}
};
