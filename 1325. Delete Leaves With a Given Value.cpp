// Time complexity - O(N)
// Space complexity- O(H)
class Solution {
    public:
    TreeNode* help(TreeNode* root,int& target)
    {
        //base case
        if(!root)
        return NULL;
        
        if(!(root->left) and !(root->right))
        {
            if(root->val==target)
            return NULL;
            
            return root;
        }
        
        //recursive calls
        //and small calculation
        TreeNode* a=help(root->left,target);
        TreeNode* b=help(root->right,target);
        
        if(!a and !b and root->val==target)
        return NULL;
        
        root->left=a;
        root->right=b;
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return help(root,target);
    }
};