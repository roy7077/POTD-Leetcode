/*------------Method-1--------*/
// unordered map
// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums)
        mp[it]++;
        
        int cnt=0;
        for(auto it:mp)
        {
            if(it.second==1)
            return -1;
            
            if(it.second%3==0)
            cnt+=(it.second)/3;
            else
            {
                cnt+=it.second/3;
                cnt++;
            }
        }
        return cnt;
    }
};

/*------------Method-2--------*/
// sorting
// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution {
    public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int cnt=1;
        int i=1;
        while(i<nums.size())
        {
            if(nums[i]==nums[i-1])
            cnt++;
            else
            {
                if(cnt==1)
                return -1;
                
                if(cnt%3==0)
                ans+=cnt/3;
                else
                {
                    ans+=cnt/3;
                    ans++;
                }
                cnt=1;
            }
            i++;
        }
        
        if(cnt==1)
        return -1;

        if(cnt%3==0)
        ans+=cnt/3;
        else
        {
            ans+=cnt/3;
            ans++;
        }
        
        return ans;
    }
};
