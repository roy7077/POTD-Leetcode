/*
 Method - 1
 Sorting
 Time complexity - O(NlogN)
 Space complexity- O(1)
*/
#define ll long long
class Solution {
    public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int cnt=1;
        ll a=-1e18;
        ll b=-1e18;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            cnt++;
            else
            {
                if(cnt==1)
                {
                    if(a<=-1e18)
                    a=nums[i-1];
                    else
                    {
                        b=nums[i-1];
                        cnt=0;
                        break;
                    }
                }
                cnt=1;
            }
        }
        
        if(cnt==1)
        b=nums[n-1];
        
        return {int(a),(int)b};
    }
};



/*
 Method - 2
 Unordered map
 Time complexity - O(N)
 Space complexity- O(N)
*/
#define ll long long
class Solution {
    public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto& it:nums)
        mp[it]++;
        
        ll a=-1e18;
        ll b=-1e18;
        
        for(auto& it:mp)
        {
            if(it.second==1)
            {
                if(a<=-1e18)
                a=it.first;
                else
                {
                    b=it.first;
                    break;
                }
            }
        }
        return {(int)a,(int)b};
    }
};