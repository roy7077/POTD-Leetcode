// MEMOIZATION
class Solution {
    public:
    int help(vector<int>& nums,int i,int pre,vector<vector<int>>& memo)
    {
        //base case
        if(i>=nums.size())
        return 0;
        
        //memo check
        if(pre!=-1 and memo[i][pre]!=-1)
        return memo[i][pre];
        
        //recursive calls
        //small calculation
        int a=help(nums,i+1,pre,memo);
        int b=0;
        if(pre==-1 or nums[i]>nums[pre])
        b=1+help(nums,i+1,i,memo);
        
        if(pre==-1)
        return max(a,b);
        
        return memo[i][pre]=max(a,b);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> memo(nums.size(),vector<int>(nums.size()+1,-1));
        return help(nums,0,-1,memo);
    }
};

