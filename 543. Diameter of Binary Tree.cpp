/* Method - 1
   Time complexity - O(N)
   Space complexity- O(H)
*/
class Solution {
    public:
    int help(TreeNode* root,int& maxi)
    {
        //base case
        if(!root)
        return 0;
        
        //recursive calls
        //and small calculation
        int a=help(root->left,maxi);
        int b=help(root->right,maxi);
        
        maxi=max(maxi,a+b);
        return max(a,b)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        int height=help(root,maxi);
        return maxi;
    }
};

/* Method - 2
   Time complexity - O(N)
   Space complexity- O(H)
*/
typedef pair<int, int> pi; 
class Solution {
    public:
    pi helper(TreeNode* root)
    {
        if(root==NULL)
        {
            pair<int,int> p;
            p.first=0;
            p.second=0;
            return p;
        }
        
        pi p1,p2,pf;
        p1=helper(root->left);
        p2=helper(root->right);
        
        pf.second=max({p1.first+p2.first,p1.second,p2.second});
        pf.first=max(p1.first,p2.first)+1;
        return pf;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).second;
    }
};