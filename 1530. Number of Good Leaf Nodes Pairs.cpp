
// Time complexity - O(N^2)
// Space complexity- O(N + H)
class Solution {
    public:
    vector<int> help(TreeNode* root,int& distance,int& cntPairs)
    {
        //base case
        if(!root)
        return {};
        
        if(!(root->left) and !(root->right))
        return {1};
        
        //recursive calls
        //and small calculation
        vector<int> a=help(root->left,distance,cntPairs);
        vector<int> b=help(root->right,distance,cntPairs);
        
        int i=a.size()-1;
        int j=0;
        
        while(i>=0 and j<b.size())
        {
            if((a[i]+b[j])<=distance)
            {
                cntPairs+=(i+1);
                j++;
            }
            else
            i--;
        }
        
        vector<int> temp;
        i=0;
        j=0;
        
        while(i<a.size() and j<b.size())
        {
            if(a[i]<=b[j])
            {
                temp.push_back(a[i]+1);
                i++;
            }
            else
            {
                temp.push_back(b[j]+1);
                j++;
            }
        }
        
        while(i<a.size())
        {
            temp.push_back(a[i]+1);
            i++;
        }
        
        while(j<b.size())
        {
            temp.push_back(b[j]+1);
            j++;
        }
        
        return temp;
    }
    int countPairs(TreeNode* root, int distance) {
        int cntPairs=0;
        help(root,distance,cntPairs);
        return cntPairs;
    }
};
