// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string> ans;
        int i=0;
        int size=target.size();
        
        for(int j=1;j<=n;j++)
        {
            if(i>=size)
            break;
            
            if(j!=target[i])
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            else
            {
                ans.push_back("Push");
                i++;
            }
        }
        return ans;
    }
};
