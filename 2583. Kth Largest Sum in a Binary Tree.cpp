// Time complexity - O(NlogN)
// Space complexity- O(N+N)
#define ll long long
class Solution {
    public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        while(!q.empty())
        {
            ll size=q.size();
            ll sum=0;
            while(size--)
            {
                TreeNode* node=q.front();
                q.pop();
                
                sum+=node->val;
                if(node->left)
                q.push(node->left);
                
                if(node->right)
                q.push(node->right);
            }
            
            if(pq.size()<k)
            pq.push(sum);
            else if(pq.top()<sum)
            {
                pq.pop();
                pq.push(sum);
            }
        }
        
        return pq.size()>=k ? pq.top() : -1;
    }
};
