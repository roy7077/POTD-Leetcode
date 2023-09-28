// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int i=0;
        int j=0;
        while(i<nums.size() and j<nums.size())
        {
            if(nums[j]&1)
            j++;
            else
            {
                int temp=nums[j];
                nums[j]=nums[i];
                nums[i]=temp;
                i++;
                j++;
            }
        }
        
        return nums;
    }
};