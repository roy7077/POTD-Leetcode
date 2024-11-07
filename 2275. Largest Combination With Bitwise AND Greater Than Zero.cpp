// Time complexity - O(N)
// Space complexity- O(32) - constant
class Solution {
    public:
    int largestCombination(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto& it:nums)
        {
            for(int i=0;i<32;i++)
            {
                if(it&(1<<i))
                mp[i]++;
            }
        }
        
        int maxLen=0;
        for(auto& it:mp)
        maxLen=max(maxLen,it.second);
        
        return maxLen;
    }
};
