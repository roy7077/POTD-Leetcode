/*
 Method - 1
 Prefix and Suffix 
 Time complexity - O(N)
 Space complexity- O(N)
*/
class Solution {
    public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int pre[n];
        int suf[n];
        
        //prefix
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
        pre[i]=nums[i]*pre[i-1];
        
        //suffix
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        suf[i]=nums[i]*suf[i+1];
        
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            if(i-1>=0 and i+1<n)
            ans[i]=pre[i-1]*suf[i+1];
            else if(i-1>=0)
            ans[i]=pre[i-1];
            else
            ans[i]=suf[i+1];
        }
        return ans;
    }
};


/*
 Method - 2
 Prefix and Suffix - without space
 Time complexity - O(N)
 Space complexity- O(1)
*/
class Solution {
    public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        int pre=1;
        for(int i=0;i<n;i++)
        {
            ans[i]*=pre;
            pre*=nums[i];
        }
        
        pre=1;
        for(int i=n-1;i>=0;i--)
        {
            ans[i]*=pre;
            pre*=nums[i];
        }
        return ans;
    }
};