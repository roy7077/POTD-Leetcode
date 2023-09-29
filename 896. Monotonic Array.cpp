// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    bool isMonotonic(vector<int>& nums) {
        
        bool flag=0;
        bool inc=0;
        bool dec=0;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]>nums[i] and dec)
                return false;
            else if(nums[i+1]<nums[i] and inc)
                return false;
            
            if(nums[i+1]>nums[i])
                inc=1;
            else if(nums[i+1]<nums[i])
                dec=1;
        }
        
        return true;
    }
};