// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution {
    public:
    int reductionOperations(vector<int>& nums) {
        
        sort(nums.begin(),nums.end(),greater<int>());
        int cnt(0);
        int i(0);
        int j(0);
        while(j<nums.size())
        {
            if(nums[i]==nums[j])
            j++;
            else
            {
               cnt+=(j);
               i=j;
            }
        }
        return cnt;
    }
};