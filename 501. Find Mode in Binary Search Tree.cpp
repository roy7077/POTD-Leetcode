// time complexity - O(N)
// Space complexity- O(N)
class Solution {
   public:
    
    void help(TreeNode* root,unordered_map<int,int>& mp)
    {
        //base case
        if(!root)
        return ;
        
        //recursive calls
        //small calculation
        mp[root->val]++;
        help(root->left,mp);
        help(root->right,mp);
    }
    
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp;
        help(root,mp);
        
        int maxi=0;
        int ans=0;
        for(auto it:mp)
        {
            if(it.second>maxi)
            {
                maxi=it.second;
                ans=it.first;
            }
        }
        
        vector<int> v;
        for(auto it:mp)
        {
            if(it.second==maxi)
            v.push_back(it.first);
        }
        
        sort(v.begin(),v.end());
        return v;
    }
};