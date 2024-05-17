// Time complexity - O(N)
// Space complexity- O(H)
class Solution {
    public:
    bool help(TreeNode* root)
    {
        if(!root)
        return 0;
        
        if(!(root->left) and !(root->right))
        return root->val;
        
        bool a=help(root->left);
        bool b=help(root->right);
        
        if(root->val==2)
        return (a or b);
        
        return (a and b);
    }
    bool evaluateTree(TreeNode* root) {
        return help(root);
    }
};