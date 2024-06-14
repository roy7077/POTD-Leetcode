// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    int minIncrementForUnique(vector<int>& nums) {
        int mini=1e9;
        int maxi=0;
        unordered_map<int,int> mp;
        for(auto& it:nums)
        {
            mp[it]++;
            mini=min(mini,it);
            maxi=max(maxi,it);
        }
        
        int ans=0;
        int cnt=0;
        
        int i=mini;
        while(1)
        {
            if(i>maxi and cnt<=0)
            break;
            
            ans+=cnt;
            if(mp[i]==0)
            {
                if(cnt)
                cnt--;
            }
            else if(mp[i]>1)
            cnt+=mp[i]-1;
            
            i++;
        }
        return ans;
    }
};
