// Time complexity - O(N)
// Space complexity -O(height of tree)
typedef pair<int,int> pi;
class Solution {
    public:
    pi help(TreeNode* root,int& start,int& ans)
    {
        //base case
        if(!root)
        return {0,0};
        
        //recursive calls
        //small calculation
        auto a=help(root->left,start,ans);
        auto b=help(root->right,start,ans);
        
        if(root->val==start)
        {
            ans=max({a.first,b.first,ans});
            return {1,1};
        }
        
        if(a.second)
        {
            ans=max({a.first+b.first,ans});
            return {a.first+1,1};
        }
        else if(b.second)
        {
           ans=max({a.first+b.first,ans});
           return {b.first+1,1}; 
        }
        
        //ans=max({a,b,ans});
        return {max(a.first,b.first)+1,0};
    }
    int amountOfTime(TreeNode* root, int start) {
        int ans=0;
        auto call=help(root,start,ans);
        return ans;
    }
};
