// Sliding window
// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int i=0;
        int j=0;
        int maxLen=0;
        while(j<nums.size())
        {
            mp[nums[j]]++;
            while(mp[nums[j]]>k and i<=j)
            {
                mp[nums[i]]--;
                if(mp[nums[i]]<=0)
                mp.erase(nums[i]);
                
                i++;
            }
           maxLen=max(maxLen,j-i+1); 
           j++;
        }
        return maxLen;
    }
};