// Time complexity - O(N)
// Space complexity- O(height of tree)
class Solution {
    public:
    int help(TreeNode* root,int low,int high)
    {
        //base case
        if(!root)
        return 0;
        
        //recursive calls
        //small calculation
        int sum=0;
        if(root->val>=low and root->val<=high)
        sum+=root->val;
        
        int a=help(root->left,low,high);
        int b=help(root->right,low,high);
        return a+b+sum;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return help(root,low,high);
    }
};