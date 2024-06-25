// Time complexity - O(N)
// Space complexity- O(Height of tree)
class Solution {
    public:
    int help(TreeNode* root,int add)
    {
        //base case
        if(!root)
        return 0;
        
        if(root->left==NULL and root->right==NULL)
        {
            int temp=root->val;
            root->val=(root->val)+add;
            return temp;
        }
        
        //recursive calls
        //and small calculation
        int a=help(root->right,add);
        int temp=root->val;
        root->val=a+root->val+add;
        int b=help(root->left,root->val);
        
        return (b+temp+a);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int ans=help(root,0);
        return root;
    }
};