// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution {
    public:
    int minPairSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int maxi(0);
        int i(0);
        int j(nums.size()-1);
        
        while(i<j)
        {
            int sum=nums[i]+nums[j];
            maxi=max(sum,maxi);
            i++;
            j--;
        }
        return maxi;
    }
};

