// Method - 1
// Sorting
// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution {
    public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
        if (a<=0)
        return false; // Move -1 to the end
        else if (b<=0)
        return true; // Move -1 to the end
        else
        return a<b; // Normal comparison for non -1 elements
      });

        int num=1;
        int i=0;
        while(i<nums.size()-1)
        {
            if(nums[i]<0)
            break;
            
            if(nums[i]!=nums[i+1])
            {
                if(nums[i]!=num)
                return num;
                num++;
            }
            
            i++;
        }
        
        if(i==nums.size()-1)
        {
            if(num!=nums[nums.size()-1])
            return num;

            return nums[nums.size()-1]+1;
        }
        
        return num;
    }
};



// Method - 2
// Unordered map
// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxi=0;
        for(auto it:nums)
        {
            mp[it]++;
            maxi=max(maxi,it);
        }
        
        for(int i=1;i<=maxi;i++)
        {
            if(!mp.count(i))
            return i;
        }
        return maxi+1;
    }
};


// Method - 3
// Swaping
// Time complexity - O(N+constant)
// Space complexity- O(1)
class Solution {
    public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]>0 and nums[i]<=nums.size() and nums[nums[i]-1]!=nums[i])
            {
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i+1)
            return i+1;
        }
        return nums[nums.size()-1]+1;
    }
};