/* Method - 1
   DFS
   Time complexity - O(N)
   Space complexity- O(H)
*/
typedef pair<int,int> pi;
class Solution {
    public:
    void help(TreeNode* root,pi& ans,int h)
    {
        //base case
        if(!root)
        return ;
        
        //recursive calls
        //small calculation
        help(root->left,ans,h+1);
        help(root->right,ans,h+1);
        
        if(h>ans.first)
        {
            ans.first=h;
            ans.second=root->val;
        }
        
    }
    int findBottomLeftValue(TreeNode* root) {
        pi ans={-1,0};
        help(root,ans,0);
        return ans.second;
    }
};

/* Method - 2
   BFS
   Time complexity - O(N)
   Space complexity- O(H)
*/
class Solution {
    public:
    int findBottomLeftValue(TreeNode* root) {
        int ans=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                
                if(i==0)
                ans=node->val;
                
                if(node->left)
                q.push(node->left);
                
                if(node->right)
                q.push(node->right);
            }
        }
        return ans;
    }
};