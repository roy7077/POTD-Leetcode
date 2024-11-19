#define ll long long
class Solution {
    public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int i=0;
        int j=0;
        ll sum=0;
        
        while(j<k)
        {
            mp[nums[j]]++;
            sum+=nums[j];
            j++;
        }
        
        ll maxSum=0;
        if(mp.size()==k)
        maxSum=sum;
        
        while(j<nums.size())
        {
            sum+=nums[j];
            mp[nums[j]]++;
            
            sum-=nums[i];
            mp[nums[i]]--;
            
            if(mp[nums[i]]==0)
            mp.erase(nums[i]);
            
            if(mp.size()==k)
            maxSum=max(maxSum,sum);
            
            j++;
            i++;
        }
        
        return maxSum;
    }
};
