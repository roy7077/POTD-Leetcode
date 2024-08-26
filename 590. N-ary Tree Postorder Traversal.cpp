class Solution {
    public:
    void help(Node* root,vector<int>& ans)
    {
        // base case
        if(!root)
        return ;
        
        // recursive calls
        // and small calculation
        for(auto& child:root->children)
        help(child,ans);
        
        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        help(root,ans);
        return ans;
    }
};


