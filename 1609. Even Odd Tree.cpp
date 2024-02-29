
/* Method - 1
   DFS
   Time complexity - O(N)
   Space complexity- O(H+H)
*/
class Solution {
    public:
    bool help(TreeNode* root,int h,unordered_map<int,int>& mp)
    {
        //base case
        if(!root)
        return 1;
        
        //recursive calls
        //and small calculation
        if(h&1)
        {
            if((root->val)&1)
            return 0;
            else if(mp.count(h)==0)
            mp[h]=root->val;
            else if(mp[h]<=root->val)
            return 0;
            else
            mp[h]=root->val;
        }
        else
        {
            if((root->val)%2==0)
            return 0;
            else if(mp.count(h)==0)
            mp[h]=root->val;
            else if(mp[h]>=root->val)
            return 0;
            else
            mp[h]=root->val;
        }
        
        bool a=help(root->left,h+1,mp);
        if(!a)
        return 0;
        
        bool b=help(root->right,h+1,mp);
        return b;
    }
    bool isEvenOddTree(TreeNode* root) {
        unordered_map<int,int> mp;
        return help(root,0,mp);
    }
};


/* Method - 2
   BFS
   Time complexity - O(N)
   Space complexity- O(W)
*/
class Solution {
    public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int h=-1;
        while(!q.empty())
        {
            h++;
            int size=q.size();
            int pre=-1;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                
                if(node->left)
                q.push(node->left);
                
                if(node->right)
                q.push(node->right);
                
                //if you are at 1st element of a level
                if(i==0)
                {
                    if(h&1)
                    {
                        if((node->val)&1)
                        return 0;
                    }
                    else
                    {
                        if((node->val)%2==0)
                        return 0;
                    }
                    
                    pre=node->val;
                    continue;
                }
                
                
                if(h&1)
                {
                    if((node->val)&1 or (node->val)>=pre)
                    return 0;
                }
                else
                {
                    if((node->val)%2==0 or (node->val)<=pre)
                    return 0;
                }
                
                pre=node->val;
            }
        }
        return 1;
    }
};