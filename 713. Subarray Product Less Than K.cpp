// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int cnt=0;
        int pro=1;
        while(j<nums.size())
        {
            pro*=nums[j];
            while(pro>=k and i<=j)
            {
                pro/=nums[i];
                i++;
            }
            
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
};