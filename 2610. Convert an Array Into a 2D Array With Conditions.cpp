// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        int n=nums.size();
        int maxi=-1;
        vector<pair<int,int>> p;
        sort(nums.begin(),nums.end());
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
            cnt++;
            else
            {
                maxi=max(maxi,cnt);
                p.push_back({nums[i-1],cnt});
                cnt=1;
            }
        }
        
        maxi=max(maxi,cnt);
        p.push_back({nums[n-1],cnt});
        
        vector<vector<int>> ans(maxi);
        int i=0;
        while(i<maxi)
        {
            for(auto& it:p)
            {
                if(it.second>0)
                ans[i].push_back(it.first);
                
                it.second--;
            }
            i++;
        }
        return ans;
    }
};