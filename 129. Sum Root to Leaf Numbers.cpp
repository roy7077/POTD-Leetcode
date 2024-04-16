// Time complexity - O(N)
// Space complexity- O(height of the tree)
class Solution {
public:
    int help(TreeNode* root,int num)
    {
        //base case  
        if(!(root->left) and !(root->right))
        {
            num*=10;
            num+=root->val;
            return num;
        }
        
        //recursive calls
        //and small calculation
        num*=10;
        num+=root->val;
        int a,b;
        a=b=0;
        
        if(root->left)
        a=help(root->left,num);
        
        if(root->right)
        b=help(root->right,num);
        
        return (a+b);
    }
    int sumNumbers(TreeNode* root) {
        int num=0;
        return help(root,num);
    }
};