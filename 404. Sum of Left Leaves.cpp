// Time complexity - O(N)
// Space complexity- O(height of the tree)
class Solution {
    public:
    int help(TreeNode* root,bool isLeft)
    {
        //base case
        if(!root)
        return 0;
        
        if(root->left==NULL and root->right==NULL)
        {
            if(isLeft)
            return root->val;
            
            return 0;
        }
        
        //recursive calls
        //and small calculation
        int a=help(root->left,1);
        int b=help(root->right,0);
        return (a+b);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return help(root,0);
    }
};
