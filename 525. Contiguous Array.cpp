// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    int findMaxLength(vector<int>& nums) {
        int sum=0;
        int maxLen=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            sum+=-1;
            else
            sum++;
            
            if(sum==0)
            maxLen=i+1;
            else if(mp.count(sum))
            maxLen=max(maxLen,i-mp[sum]);
            else
            mp[sum]=i;
        }
        return maxLen;
    }
};