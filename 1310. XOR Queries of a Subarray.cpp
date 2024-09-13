// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> xorr(n,0);
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                xorr[i]=arr[i];
                continue;
            }
            
            xorr[i]=arr[i]^xorr[i-1];
        }
        
        vector<int> ans;
        for(auto& q:queries)
        {
            int l=q[0];
            int r=q[1];
            
            if(l==0)
            ans.push_back(xorr[r]);
            else
            ans.push_back(xorr[r]^xorr[l-1]);
        }
        return ans;
    }
};
