class Solution {
    public:
    void help(TreeNode* root,vector<int>& ans)
    {
        // base case
        if(!root)
        return ;
        
        // recursive calls
        // and small calculation
        help(root->left,ans);
        help(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        help(root,ans);
        return ans;
    }
};
