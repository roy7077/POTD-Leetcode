//Method - 1
// Time complexity - O(N)
// Space complexity- O(N+height of tree)
class Solution {
    public:
    int help(TreeNode* root,unordered_map<int,int>& mp)
    {
        //base case
        if(!root)
        return 0;
        
        if(root->left==NULL and root->right==NULL)
        {
            mp[root->val]++;
            int cnt=0;
            int even=0;
            int odd=0;
            for(auto it:mp)
            {
                cnt+=it.second;
                if(it.second&1)
                odd++;
                else
                even++;
            }
            
            mp[root->val]--;
            if(cnt&1 and odd>=2)
            return 0;
            else if(cnt%2==0 and odd)
            return 0;
            
            return 1;
        }
        
        //recursive calls
        //small calculation
        mp[root->val]++;
        int a=help(root->left,mp);
        int b=help(root->right,mp);
        mp[root->val]--;
        
        return (a+b);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> mp;
        return help(root,mp);
    }
};


// Method 2
/* bit
we know that , data of nodes are in the range of 1 to 9.
we can make bitset , 
and keep in doing xor. if we get same data then the xor of the same number is 0 , 

at the last we will check that , if count of set bits are more than 1 return 0;

how to check ?
bit&(bit-1)==0,
basically we are checking . is this number power of 2 or not , if it is a power of 2
then there will be 1 or 0 set bit , otherwise there will be more than 1 set bit.
*/
// Time complexity - O(N)
// Space complexity- O(height of tree)
class Solution {
    public:
    int help(TreeNode* root,int bit)
    {
        //base case
        if(!root)
        return 0;
        
        bit^=(1<<(root->val));
        if(root->left==NULL and root->right==NULL)
        {
            if((bit&(bit-1))==0)
            return 1;
        }
        
        int a=help(root->left,bit);
        int b=help(root->right,bit);
        
        return (a+b);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int bit=0;
        return help(root,bit);
    }
};