// Time complexity - O(Number of nodes)
// Space complexity- O(height of tree)
class Solution {
    public:
    void help(TreeNode* root,vector<int>& v)
    {
        if(!root)
        return ;
        
        help(root->left,v);
        v.push_back(root->val);
        help(root->right,v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        help(root,ans);
        return ans;
    }
};