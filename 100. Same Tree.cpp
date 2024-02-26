
// Time complexity - O(N)
// Space complexity- O(H)
class Solution {
    public:
    bool help(TreeNode* root1,TreeNode* root2)
    {
        //base case
        if((!root1 and root2) or (root1 and !root2))
        return 0;
        
        if(!root1 and !root2)
        return 1;
        
        if((root1->val)!=(root2->val))
        return 0;
        
        //recursive calls
        //and small calculation
        bool a=help(root1->left,root2->left);
        if(!a)
        return 0;
        
        bool b=help(root1->right,root2->right);
        return b;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return help(p,q);
    }
};