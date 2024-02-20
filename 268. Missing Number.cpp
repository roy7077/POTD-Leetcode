// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(auto it:nums)
        sum+=it;
        
        int sum2=(n*(n+1))/2;
        return (sum2-sum);
    }
};
