// Time complexity - O(N)
// Space complexity -O(height of tree + N)
class Solution {
    public:
    void help(TreeNode* root,vector<int>& ans)
    {
        //base case
        if(!root)
        return ;
        
        //small calculation
        //recurisve calls
        if(root->left==NULL and root->right==NULL)
        {
            ans.push_back(root->val);
            return ;
        }
        
        help(root->left,ans);
        help(root->right,ans);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1;
        vector<int> ans2;
        
        help(root1,ans1);
        help(root2,ans2);
        
        if(ans1.size()!=ans2.size())
        return 0;
        
        for(int i=0;i<ans1.size();i++)
        {
            if(ans1[i]!=ans2[i])
            return 0;
        }
        return 1;
    }
};