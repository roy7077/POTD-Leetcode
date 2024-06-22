// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cnt=0;
        int i=0;
        int j=0;
        int oddCnt=0;
        while(j<nums.size())
        {
            if(nums[j]&1)
            oddCnt++;
            
            while(oddCnt>k)
            {
                if(nums[i]&1)
                oddCnt--;
                i++;
            }
            
            int extraCnt=0;
            for(int l=i;l<=j;l++)
            {
                if(nums[l]%2==0)
                extraCnt++;
                else
                break;
            }
            
            if(oddCnt==k)
            cnt+=(extraCnt+1);
            
            j++;
        }
        return cnt;
    }
};

// [2,2,2,1,1,1,1,2,2,1,2,2,4]
// 2