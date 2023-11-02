// Time complexity - O(N)
// Space complexity- O(N
class Solution {
    public:
    pair<int,int> help(TreeNode* root,int& cnt)
    {
        //base case
        if(!root)
        return {0,0};
        
        //recursive calls
        auto left=help(root->left,cnt);
        auto right=help(root->right,cnt);
        
        int sum=left.first+right.first+root->val;
        int num=left.second+right.second+1;
        
        if((sum/num)==root->val)
        cnt++;
        
        cout<<cnt<<endl;
        return {sum,num};
    }
    int averageOfSubtree(TreeNode* root) {
        int cnt=0;
        auto ans=help(root,cnt);
        return cnt;
    }
};
