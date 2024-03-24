// Method - 1
// Unordered map
// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums)
        {
            if(mp[it]>=1)
            return it;
            
            mp[it]++;
        }
        return -1;
    }
};


// Method - 2
// sorting
// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution {
    public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=1;
        while(i<nums.size())
        {
            if(nums[i]==nums[i-1])
            return nums[i];
            
            i++;
        }
        return -1;
    }
};


// Method - 3
// Inplace
// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int findDuplicate(vector<int>& nums) {
        int maxi=1e5+9;
        for(auto& it:nums)
        {
            int ele=it%maxi;
            int num=nums[ele]%maxi;
            int fre=nums[ele]/maxi;
            
            if(fre>=1)
            return ele;
            
            nums[ele]=((fre+1)*maxi)+num;
        }
        return -1;
    }
};