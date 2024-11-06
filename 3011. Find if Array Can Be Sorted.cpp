
// Time complexity - O(N^2 * 32)
// Space complexity- O(1)
class Solution {
    public:
    bool sameSetBits(int a,int b)
    {
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<32;i++)
        {
            if(a&(1<<i))
            cnt1++;
            
            if(b&(1<<i))
            cnt2++;
        }
        
        return cnt1==cnt2;
    }
    
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(nums[j]>nums[j+1])
                {
                    if(sameSetBits(nums[j],nums[j+1]))
                    swap(nums[j],nums[j+1]);
                    else
                    return 0;
                }
            }
        }
        return 1;
    }
};
