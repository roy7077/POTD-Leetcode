
// Method - 1
// Unordered map
// Time complexity - O(N)
// Space complexity- O(N+N)
class Solution {
    public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto it:nums)
        mp[it]++;
        
        for(auto it:mp)
        {
            if(it.second==2)
            ans.push_back(it.first);
        }
        return ans;
    }
};


// Method - 2
// Sorting
// Time complexity - O(NlogN)
// Space complexity- O(N+N)
class Solution {
    public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int cnt=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            cnt++;
            else
            {
                if(cnt==2)
                ans.push_back(nums[i-1]);
                
                cnt=1;
            }
        }
        
        if(cnt==2)
        ans.push_back(nums[nums.size()-1]);
        
        return ans;
    }
};


// Method - 3
// Inplace
// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    vector<int> findDuplicates(vector<int>& nums) {
        nums.push_back(0);
        int maxi=1e5+9;
        for(int i=0;i<nums.size();i++)
        {
            int orignal=nums[i]%maxi;
            
            int ori=nums[orignal]%maxi;
            int cnt2=nums[orignal]/maxi;
            
            nums[orignal]=((cnt2+1)*maxi)+ori;
        }
        
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int cnt=nums[i]/maxi;
            if(cnt==2)
            ans.push_back(i);
        }
        return ans;
    }
};