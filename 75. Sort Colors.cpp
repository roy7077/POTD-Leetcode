// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int j=0;
        
        //seting zero at the begining
        while(j<nums.size())
        {
            if(nums[j]==0)
            {
                int temp=nums[j];
                nums[j]=nums[i];
                nums[i]=temp;
                i++;
            }
            j++;
        }
        
        //arranging one after zero
        int k=i;
        while(k<nums.size())
        {
            if(nums[k]==1)
            {
                int temp=nums[k];
                nums[k]=nums[i];
                nums[i]=temp;
                i++;
            }
            k++;
        }
    }
};