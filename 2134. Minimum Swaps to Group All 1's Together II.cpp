// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int minSwaps(vector<int>& nums) {
        
        // count total number of 1's in nums
        int oneCnt=0;
        for(auto& it:nums)
        oneCnt+=it;
        
        
        // make window of size oneCnt
        // and count zeros into this window
        int n=nums.size();
        int i=0;
        int j=0;
        int zeroCnt=0;
        int ans=1e9;
        while(j<oneCnt)
        {
            if(nums[j]==0)
            zeroCnt++;
            
            j++;
        }
        
        // sliding window of size oneCnt
        ans=min(ans,zeroCnt);
        while(j<(n+oneCnt))
        {
            if(nums[i]==0)
            zeroCnt--;
            
            if(nums[j%n]==0)
            zeroCnt++;
            
            i++;
            j++;
            ans=min(ans,zeroCnt);
        }
        return ans;
    }
};

/*

[1,1,0,0,1]


*/
