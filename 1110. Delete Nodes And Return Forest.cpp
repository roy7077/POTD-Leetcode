
// method - 1
typedef pair<TreeNode*,bool> pi;
class Solution {
    public:
    TreeNode* help(TreeNode* root,unordered_set<int>& st,vector<TreeNode*>& ans)
    {
        //base case
        if(!root)
        return NULL;
        
        //recursive calls
        //and small calculation
        TreeNode* a=help(root->left,st,ans);
        TreeNode* b=help(root->right,st,ans);
        
        root->left=a;
        root->right=b;
        
        if(st.count(root->val))
        {
            
            if(root->left)
            ans.push_back(root->left);
            
            if(root->right)
            ans.push_back(root->right);
            
            delete root;
            return NULL;
        }
        
        return root;
    }
//     void traversal(TreeNode* root,vector<TreeNode*>& nodes)
//     {
//         //base case
//         if(!root)
//         return ;
        
//         nodes.push_back(root);
        
//         traversal(root->left,nodes);
//         traversal(root->right,nodes);
//     }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        bool flag=0;
        unordered_set<int> st;
        for(auto& it:to_delete)
        {
            if(it==root->val)
            flag=1;
            
            st.insert(it);
        }
        
        vector<TreeNode*> roots;
        help(root,st,roots);
        
        if(flag)
        return roots;
        
        for(auto& it:roots)
        {
            if(it==root)
            return roots;
        }
        
        roots.push_back(root);
//         vector<vector<TreeNode*>> ans;
//         for(auto& it:roots)
//         {
//             vector<TreeNode*> temp;
//             traversal(it,temp);
//             ans.push_back(temp);
//         }
        
//         return ans;
        return roots;
    }
};

    // 1
    //   2
    //     3
    //       4


//   1
// 2    4
//    3
