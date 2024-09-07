// Memoization
class Solution {
    public:
    map<pair<ListNode*, TreeNode*>, bool> memo;
    bool help(ListNode* head,TreeNode* root,ListNode* topHead)
    {
        // base case
        if(!head)
        return 1;
        
        if(!root)
        return 0;
        
        // memo check
        if(memo.count({head,root}))
        return memo[{head,root}];
        
        // recursive calls
        // and small calculation
        if((head->val)==root->val)
        {
            bool a=help(head->next,root->left,topHead);
            if(a)
            return memo[{head,root}]=1;
            
            bool b=help(head->next,root->right,topHead);

            if(a or b)
            return memo[{head,root}]=1;
        }
        
        bool a=help(topHead,root->left,topHead);
        if(a)
        return memo[{head,root}]=1;
        
        bool b=help(topHead,root->right,topHead);
        
        if(a or b)
        return memo[{head,root}]=1;
        
        return memo[{head,root}]=0;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return help(head,root,head);
    }
};
