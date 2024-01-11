// Time complexity - O(N)
// Space complexity- O(height of tree)
typedef pair<int,int> pi;
class Solution {
    public:
    pi help(TreeNode* root,int& ans)
    {
        //base case
        if(!root)
        return {-1,-1};
        
        //recursive calls
        //small calculation
        auto a=help(root->left,ans);
        auto b=help(root->right,ans);
        
        if(a.first!=-1 and b.first!=-1)
        {
            int maxi=max(a.first,b.first);
            int mini=min(a.second,b.second);
            
            ans=max(abs(root->val-maxi),ans);
            ans=max(abs(root->val-mini),ans);
            
            return {max(maxi,root->val),min(mini,root->val)};
        }
        else if(a.first==-1 and b.first!=-1)
        {
            ans=max(abs(root->val-b.first),ans);
            ans=max(abs(root->val-b.second),ans);
            
            return {max(b.first,root->val),min(b.second,root->val)};
        }
        else if(a.first!=-1 and b.first==-1)
        {
            ans=max(abs(root->val-a.first),ans);
            ans=max(abs(root->val-a.second),ans);
            
            return {max(a.first,root->val),min(a.second,root->val)};
        }
        
        return {root->val,root->val};
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        auto call=help(root,ans);
        return ans;
    }
};