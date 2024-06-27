// Time complexity - O(N)
// Space complexity- O(N+height of tree)
class Solution {
    public:
    void traversal(TreeNode* root,vector<int>& v)
    {
        //base case
        if(!root)
        return ;
        
        //recursive calls
        //and small calculation
        traversal(root->left,v);
        v.push_back(root->val);
        traversal(root->right,v);
    }
    
    TreeNode* makeBalanced(vector<int>& v,int s,int e)
    {
        //base case
        if(s>e)
        return NULL;
        
        //recursive calls
        //and small calculation
        int mid=(s+e)/2;
        TreeNode* root=new TreeNode(v[mid]);
        TreeNode* leftNode=makeBalanced(v,s,mid-1);
        TreeNode* rightNode=makeBalanced(v,mid+1,e);
        
        root->left=leftNode;
        root->right=rightNode;
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        traversal(root,v);
        return makeBalanced(v,0,v.size()-1);
    }
};


// 1 2 3 4 5 6
     
//       4
//   2      5 
// 1   3       6
 