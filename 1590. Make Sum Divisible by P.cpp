// Unordered map
// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int remNeed=0;
        for(auto it:nums)
        {
            remNeed+=it;
            remNeed%=p;
        }
        
        if(remNeed==0)
        return 0;
        
        unordered_map<int,int> mp;
        mp[0]=-1;
        int curr=0;
        int size=1e9;
        for(int i=0;i<nums.size();i++)
        {
            curr+=nums[i];
            curr%=p;
            
            mp[curr]=i;
            
            int want=(curr-remNeed+p)%p;
            if(mp.count(want))
            {
                int remLen=i-mp[want];
                if(remLen<size)
                size=remLen;
            }
        }
        
        return size>=n ? -1:size;
    }
};
