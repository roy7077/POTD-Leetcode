// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    int numIdenticalPairs(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        int cnt=0;
        for(auto it:nums)
        {
            cnt+=mp[it];
            mp[it]++;
        }
        return cnt;
    }
};