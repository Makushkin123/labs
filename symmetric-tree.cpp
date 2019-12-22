https://leetcode.com/problems/symmetric-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//https://leetcode.com/problems/symmetric-tree/
class Solution {
public:
    bool palin(vector<int> v)
    {
        int sz=v.size();
        for(int i=0 ; i<sz ; i++)
        if(v[i]!=v[sz-1-i]) return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) 
    {
        if(!root) return true;
        int n,cn;
        queue<TreeNode*> q;
        queue<int> nq;
        TreeNode* cur;
        q.push(root);
        nq.push(root->val);
        vector<int> v;
        bool an=true;
        while(!q.empty())
        {
            an=true;
            n=q.size();
            v.clear();
            for(int i=0 ; i<n ; i++)
            {
                cur=q.front();
                cn=nq.front();
                v.push_back(cn);
                q.pop();
                nq.pop();
                if(cur) 
                {
                    an=false;
                    q.push(cur->left);
                    if(cur->left)
                    nq.push(cur->left->val);
                    else nq.push(-1);
                    
                    q.push(cur->right);
                    if(cur->right)
                    nq.push(cur->right->val);
                    else nq.push(-1);
                }
                else
                {
                    q.push(NULL);
                    q.push(NULL);
                    nq.push(-1);
                    nq.push(-1);
                }
            }
            if(!palin(v)) return false;
            if(an) break;
        }
        return true;
    }
};
