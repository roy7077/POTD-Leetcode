/* Method - 1
   Unordered map
   Time complexity - O(N)
   Space complexity- O(N)
*/
class Solution {
    public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxi=0;
        for(auto it:nums)
        {
            mp[it]++;
            maxi=max(maxi,mp[it]);
        }
        
        int cnt=0;
        for(auto it:mp)
        cnt+= it.second==maxi ? it.second : 0;
        
        return cnt;
    }
};

/* Method - 2
   Sorting
   Time complexity - O(NlogN)
   Space complexity- O(1)
*/
class Solution {
    public:
    int maxFrequencyElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=0;
        int pre=nums[0];
        int cnt=1;
        int add=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            cnt++;
            else
            {
                if(cnt==maxi)
                add++;
                else if(cnt>maxi)
                {
                    maxi=cnt;
                    add=1;
                }
                cnt=1;
            }
        }
        
        if(cnt==maxi)
        add++;
        else if(cnt>maxi)
        {
            maxi=cnt;
            add=1;
        }
        
        return add*maxi;
        
    }
};