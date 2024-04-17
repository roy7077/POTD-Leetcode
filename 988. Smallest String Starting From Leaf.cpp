// Time complexity - O(N+(number of leaf)*(height of tree))
// Space complexity- O(Height of tree)
class Solution {
    public:
    void help(TreeNode* root,string str,string& ans)
    {
        //base case
        if(!root)
        return ;
        
        str+=char((root->val)+97);
        if(!(root->left) and !(root->right))
        {
            reverse(str.begin(),str.end());
            if(ans.length()==0 or str<ans)
            ans=str;
            
            return ;
        }
        
        //recursive calls
        //and small calculation
        help(root->left,str,ans);
        help(root->right,str,ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans="";
        help(root,"",ans);
        return ans;
    }
};