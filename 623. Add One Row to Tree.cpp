// Time complexity - O(N)
// Space complexity- O(Height of the tree)
class Solution {
    public:
    void help(TreeNode* root,int& val,int depth)
    {
        //base case
        if(!root)
        return ;
        
        if(depth-1==1)
        {
            TreeNode* newTreeNode1=new TreeNode(val);
            TreeNode* newTreeNode2=new TreeNode(val);
            
            newTreeNode1->left=root->left;
            newTreeNode2->right=root->right;
            root->left=newTreeNode1;
            root->right=newTreeNode2;
            return ;
        }
        
        //recursive calls
        //and small calculation
        if(root->left)
        help(root->left,val,depth-1);
        
        if(root->right)
        help(root->right,val,depth-1);
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* newTreeNode=new TreeNode(val);
            newTreeNode->left=root;
            return newTreeNode;
        }
        
        help(root,val,depth);
        return root;
    }
};