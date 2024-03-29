// Time complexity - O(N)
// Space complexity- O(1)
#define ll long long
class Solution {
    public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll maxi=-1;
        for(auto it:nums)
        maxi=it>maxi? it:maxi;
        
        ll ans=0;
        ll cnt=0;
        int n=nums.size();
        int i=0;
        int j=0;
        while(j<nums.size())
        {
            if(nums[j]==maxi)
            cnt++;
            
            while(cnt>=k)
            {
                ans+=n-j;
                if(nums[i]==maxi)
                cnt--;
                
                i++;
            }
            j++;
        }
        return ans;
    }
};

// 1 3 2 3 
// 3 2 3
// 1 3 2 3 3
// 3 2 3 3
// 2 3 3
// 3 3