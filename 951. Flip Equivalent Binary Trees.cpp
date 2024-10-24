class Solution {
    public:
    bool help(TreeNode* root1,TreeNode* root2)
    {
        // base cases
        if(!root1 and !root2)
        return 1;
        
        if(!root1 and root2)
        return 0;
        
        if(root1 and !root2)
        return 0;
        
        if(root1->val!=root2->val)
        return 0;
        
        // recursive calls
        // and small calculation
        bool a=help(root1->left,root2->left);
        bool b=help(root1->right,root2->right);
        
        if(a and b)
        return true;
        
        // swap
        bool c=help(root1->left,root2->right);
        bool d=help(root1->right,root2->left);
        
        return c and d;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return help(root1,root2);
    }
};
