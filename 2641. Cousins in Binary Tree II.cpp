typedef pair<TreeNode*,int> pi;
// first -> child
// second-> child's bro
class Solution {
    public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pi> q;
        q.push({root,0});
        
        int sum=root->val;
        while(!q.empty())
        {
            int size=q.size();
            int lvlSum=0;
            while(size--)
            {
                auto it=q.front();
                q.pop();
        
                int reqSum=sum;
                if(it.second)
                reqSum-=it.second;
                reqSum-=it.first->val;
                
                it.first->val=reqSum;
                
                TreeNode* node=it.first;
                if(node->left)
                {
                    int temp=0;
                    if(node->right)
                    temp=node->right->val;
                    
                    q.push({node->left,temp});
                    lvlSum+=node->left->val;
                }
                
                if(node->right)
                {
                    int temp=0;
                    if(node->left)
                    temp=node->left->val;
                    
                    q.push({node->right,temp});
                    lvlSum+=node->right->val;
                }
            }
            sum=lvlSum;
        }
        return root;
    }
};
