// https://leetcode.com/problems/path-sum/
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL 
          && sum == root->val){
            return true;
        }
        return hasPathSumUtil(root->left,sum-root->val)
            || hasPathSumUtil(root->right,sum-root->val);
    }
    
    bool hasPathSumUtil(TreeNode* root, int sum){
        if (root == NULL){
            return false;
        }
        if(root->left == NULL && root->right == NULL 
          && sum == root->val){
            return true;
        }
        bool l = false;
        bool r = false;
        if(root->left != NULL)
            l = hasPathSumUtil(root->left,sum-root->val);
        if(root->right != NULL)
            r = hasPathSumUtil(root->right,sum-root->val);
        return l || r;
    }
};// https://leetcode.com/problems/path-sum/
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL 
          && sum == root->val){
            return true;
        }
        return hasPathSumUtil(root->left,sum-root->val)
            || hasPathSumUtil(root->right,sum-root->val);
    }
    
    bool hasPathSumUtil(TreeNode* root, int sum){
        if (root == NULL){
            return false;
        }
        if(root->left == NULL && root->right == NULL 
          && sum == root->val){
            return true;
        }
        bool l = false;
        bool r = false;
        if(root->left != NULL)
            l = hasPathSumUtil(root->left,sum-root->val);
        if(root->right != NULL)
            r = hasPathSumUtil(root->right,sum-root->val);
        return l || r;
    }
};
