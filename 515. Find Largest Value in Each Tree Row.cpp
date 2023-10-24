/*---------Push null after completing each level----------*/
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        
        if(!root)
        return {};
        
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        int maxi=INT_MIN;
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            
            if(!it)
            {
                ans.push_back(maxi);
                maxi=INT_MIN;
                
                if(q.empty())
                break;
                
                q.push(NULL);
                continue;
            }
            
            maxi=max(maxi,it->val);
            if(it->left)
            q.push(it->left);
            
            if(it->right)
            q.push(it->right);
        }
        
        return ans;
    }
};


/*-----------------level wise-------------------*/
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        
        if(!root)
        return {};
        
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size=q.size();
            int maxi=INT_MIN;
            while(size)
            {
                auto front=q.front();
                q.pop();
                
                maxi=max(maxi,front->val);
                
                if(front->left)
                q.push(front->left);
                
                if(front->right)
                q.push(front->right);
                
                size--;
            }
            
            ans.push_back(maxi);
        }
        
        return ans;
    }
};