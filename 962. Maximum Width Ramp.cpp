// Two pointer approach
// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        vector<int> v(n,0);
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                v[i]=nums[i];
                continue;
            }
            v[i]=max(v[i+1],nums[i]);
        }
        
        int ans=0;
        int i=0;
        int j=0;
        
        while(i<n and j<n)
        {
            if(v[j]>=nums[i])
            {
                ans=max(ans,j-i);
                j++;
            }
            else
            i++;
        }
        return ans;
    }
};
