// Time complexity - O(1)
// Space complexity- O(1)
class Solution {
    public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        int a=(nums[n-1]-1)*(nums[n-2]-1);
        int b=(nums[0]-1)*(nums[1]-1);
        
        if(a>b)
        return a;
        else
        return b;
    }
};